class MKAverage {
    class Node implements Comparable<Node> {
        int val;
        int time;
        
        Node(int val, int time) {
            this.val = val;
            this.time = time;
        }
        
        @Override
        public int compareTo(Node other) {
            return (this.val != other.val ? this.val - other.val 
                                          : this.time - other.time);
        }
    }
    
    private TreeSet<Node> set = new TreeSet<>();          // natural order
    private Deque<Node> queue = new LinkedList<>();
    private Node kLeft;
    private Node kRight;
    
    private int m, k;
    
    private int time = 0;
    private int sum = 0;

    public MKAverage(int m, int k) {
        this.m = m;
        this.k = k;
    }
    
    public void addElement(int num) {
        Node node = new Node(num, time++);

        addNode(node);
        removeNode();
        
        if (time == m) init();
    }
    
    private void init() {
        int i = 0;
        for (Node node : set) {
            if (i < k-1);
            else if (i == k-1) kLeft = node;
            else if (i < m-k) sum += node.val;
            else if (i == m-k) {
                kRight = node;
                return;
            }
            
            i++;
        }
        return;
    }
    
    private void addNode(Node node) {
        queue.offerLast(node);
        set.add(node);
        
        if (queue.size() <= m) return;
        
        if (node.compareTo(kLeft) < 0) {
            sum += kLeft.val;
            kLeft = set.lower(kLeft);
        } else if (node.compareTo(kRight) > 0) {
            sum += kRight.val;
            kRight = set.higher(kRight);
        } else {
            sum += node.val;
        } 
    }
    
    private void removeNode() {
        if (queue.size() <= m) return;
        
        Node node = queue.pollFirst();
        
        if (node.compareTo(kLeft) <= 0) {
            kLeft = set.higher(kLeft);
            sum -= kLeft.val;
        } else if (node.compareTo(kRight) >= 0) {
            kRight = set.lower(kRight);
            sum -= kRight.val;
        } else {
            sum -= node.val;
        }
        
        set.remove(node);
    }
    
    public int calculateMKAverage() {
        return (queue.size() < m ? -1 : sum / (m - 2 * k));
    }
}
