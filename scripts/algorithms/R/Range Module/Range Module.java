// Runtime: 91 ms (Top 31.23%) | Memory: 73.2 MB (Top 20.97%)
class RangeModule {
    TreeMap<Integer, Integer> map;

    public RangeModule() {
        map = new TreeMap<>();
    }

    public void addRange(int left, int right) {
        // assume the given range [left, right), we want to find [l1, r1) and [l2, r2) such that l1 is the floor key of left, l2 is the floor key of right. Like this:
        // [left, right)
        // [l1, r1) [l2, r2)
        // Note: l2 could be the same as l1, so they are either both null or both non-null
        Integer l1 = map.floorKey(left);
        Integer l2 = map.floorKey(right);

        // try to visualize each case, and what to do based on r1
        if (l1 == null && l2 == null) {
            map.put(left, right);
        }
        else if (l1 != null && map.get(l1) >= left) {
            map.put(l1, Math.max(right, map.get(l2))); // r2 will always be greater than r1, so no need to check r1
        }
        else {
            map.put(left, Math.max(right, map.get(l2)));
        }

        // we don't want to remove the range starts at left, so left should be exclusive.
        // but we want to remove the one starts at right, so right should be inclusive.
        map.subMap(left, false, right, true).clear();
    }

    public boolean queryRange(int left, int right) {
        Integer l = map.floorKey(left);
        if (l != null && map.get(l) >= right) {
            return true;
        }
        return false;
    }

    public void removeRange(int left, int right) {
        Integer l1 = map.lowerKey(left); // I used lowerKey here, since we don't care about the range starting at left, as it should be removed
        Integer l2 = map.lowerKey(right); // same, we don't care about the range starting at right

        // do this first, in case l1 == l2, the later one will change r1(or r2 in this case)
        if (l2 != null && map.get(l2) > right) {
            map.put(right, map.get(l2));
        }

        if (l1 != null && map.get(l1) > left) {
            map.put(l1, left);
        }

        // range that starts at left should be removed, so left is inclusive
        // range that starts at right should be kept, so right is exclusive
        map.subMap(left, true, right, false).clear();
    }
}