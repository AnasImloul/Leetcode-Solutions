// Runtime: 324 ms (Top 17.56%) | Memory: 57.1 MB (Top 16.13%)
class Skiplist {

        public static final int MAX_LEVEL = 4;

        private final int levels;

        private SkipListEntry head;

        private SkipListEntry tail;

        public Skiplist() {
            this(MAX_LEVEL);
        }

        public Skiplist(int levels) {
            this.levels = levels;

            //init new SkipList with defined level
            //Firstly, create the root level (level = 0) entry for left (min) and right (max)
            // and linked it
            // LEFT <------------------------------------------------> RIGHT
            SkipListEntry left = new SkipListEntry(Integer.MIN_VALUE, Integer.MIN_VALUE);
            SkipListEntry right = new SkipListEntry(Integer.MAX_VALUE, Integer.MAX_VALUE);
            left.right = right;
            right.left = left;

            // After, we can define left and right as the head and tail nodes
            // HEAD = LEFT <------------------------------------------------> RIGHT = TAIL
            this.head = left;
            this.tail = right;

            // Next, we can define left and right nodes for other levels and linked it
            // 0 HEAD = LEFT <------------------------------------------------> RIGHT = TAIL
            // ^ ^
            // | |
            // v v
            // 1 HEAD = LEFT <------------------------------------------------> RIGHT = TAIL
            // ^ ^
            // | |
            // v v
            // 2 HEAD = LEFT <------------------------------------------------> RIGHT = TAIL
            // ^ ^
            // | |
            // v v
            // 3 HEAD = LEFT <------------------------------------------------> RIGHT = TAIL
            // ^ ^
            // | |
            // v v
            // N HEAD = LEFT <------------------------------------------------> RIGHT = TAIL
            for (int i = 1; i < this.levels; i++) {
                left.down = new SkipListEntry(
                        Integer.MIN_VALUE,
                        Integer.MIN_VALUE,
                        null,
                        null,
                        left,
                        null
                );
                left = left.down;

                right.down = new SkipListEntry(
                        Integer.MAX_VALUE,
                        Integer.MAX_VALUE,
                        null,
                        null,
                        right,
                        null
                );
                right = right.down;

                left.right = right;
                right.left = left;
            }
        }

        public boolean search(int target) {
            return this.find(target).key == target;
        }

        public void add(int num) {
            // We have to always start from head
            SkipListEntry current = this.head;

            // For the searching newNode we have to:
            // 1 - start from the head
            // 2 - go down the bottom level
            while (current.hasDown()) {
                current = current.down;
            }

            // 3 - try to find newNode
            while (current.hasRight() && num > current.right.key) {
                current = current.right;
            }

            // 4 - if we found newNode on the step 3, we have to do nothing (return;)
            if (num == current.key) {
                return;
            }

            // 5 - otherwise, we have to a put new newNode on the right
            SkipListEntry newNode = new SkipListEntry(num, num, current, current.right);
            current.right.left = newNode;
            current.right = newNode;

            // 6 - have to go up one level
            // 7 - flip the coin
            // 8 - if on the step 8 true - repeat step 5
            for (int level = this.levels - 2; level >= 0; level--) {
                if (!this.coinFlip(level)) {
                    return;
                }

                // go up one level and find left node for new level
                while (!current.hasUp() && current.hasLeft()) {
                    current = current.left;
                }
                current = current.up;

                newNode.up = new SkipListEntry(
                        num,
                        num,
                        current,
                        current.right,
                        null,
                        newNode
                );
                newNode = newNode.up;

                current.right.left = newNode;
                current.right = newNode;
            }
        }

        public boolean erase(int num) {
            SkipListEntry entry = this.find(num);
            if (entry.key != num) {
                return false;
            }

            entry.left.right = entry.right;
            entry.right.left = entry.left;

        while ((entry = entry.up) != null) {
            entry.left.right = entry.right;
            entry.right.left = entry.left;
        }

            return true;
        }

        private SkipListEntry find(int key) {
            // We have to always start from head
            SkipListEntry current = this.head;

            // while node has right or down we can go down a level or right
            // 1 - we have to go right and try to find element
            // 2 - if element is not presented at this level, we have to go down a level
            // and repeat step 1
            // 3 - if we found element we have to go down to the bottom
            // if we found element we have to return it, otherwise - return last visited
            while (current != null && current.hasRight()) {
                while (current.hasRight() && key > current.right.key) {
                    current = current.right;
                }

                if (key == current.right.key) {
                    current = current.right;
                    while (current.hasDown()) {
                        current = current.down;
                    }

                    return current;
                }

                current = current.down;
            }

            return this.head;
        }

        private boolean coinFlip(int level) {
            return ThreadLocalRandom.current().nextInt(this.levels - level) == 0;
        }

        public static class SkipListEntry {

            private final int key;

            private final int value;

            private SkipListEntry up;

            private SkipListEntry down;

            private SkipListEntry left;

            private SkipListEntry right;

            public SkipListEntry(int key, int value) {
                this(key, value, null, null, null, null);
            }

            public SkipListEntry(int key,
                                 int value,
                                 SkipListEntry left,
                                 SkipListEntry right) {
                this(key, value, left, right, null, null);
            }

            public SkipListEntry(int key,
                                 int value,
                                 SkipListEntry left,
                                 SkipListEntry right,
                                 SkipListEntry up,
                                 SkipListEntry down) {
                this.key = key;
                this.value = value;
                this.left = left;
                this.right = right;
                this.up = up;
                this.down = down;
            }

            public int getKey() {
                return this.key;
            }

            public int getValue() {
                return this.value;
            }

            public SkipListEntry left() {
                if (!this.hasLeft()) {
                    return null;
                }

                return this.left;
            }

            public void setLeft(SkipListEntry entry) {
                this.left = Objects.requireNonNull(entry);
            }

            public SkipListEntry right() {
                if (!this.hasRight()) {
                    return null;
                }

                return this.right;
            }

            public void setRight(SkipListEntry entry) {
                this.right = Objects.requireNonNull(entry);
            }

            public SkipListEntry up() {
                if (!this.hasUp()) {
                    return null;
                }

                return this.up;
            }

            public void setUp(SkipListEntry entry) {
                this.up = Objects.requireNonNull(entry);
            }

            public SkipListEntry getDown() {
                return this.down;
            }

            public SkipListEntry down() {
                if (!this.hasDown()) {
                    return null;
                }

                return this.down;
            }

            public void setDown(SkipListEntry entry) {
                this.down = Objects.requireNonNull(entry);
            }

            public boolean hasLeft() {
                return this.left != null;
            }

            public boolean hasRight() {
                return this.right != null;
            }

            public boolean hasUp() {
                return this.up != null;
            }

            public boolean hasDown() {
                return this.down != null;
            }
        }
    }