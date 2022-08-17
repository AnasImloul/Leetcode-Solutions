class Solution {
    int[] tree;
    int[] arr;
    int target;
    int min;
    
    public int closestToTarget(int[] arr, int target) {
        int n = arr.length;
        this.arr = arr;
        this.target = target;
        tree = new int[n << 2];
        Arrays.fill(tree, (1 << 31) - 1);               // initialize
        min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            add(i, 0, n, 0);
        }
        return min;
    }
    private void add(int x, int l, int r, int n) {
        if (l == r) {
            tree[n] = arr[x];
            min = Math.min(min, Math.abs(tree[n] - target));
            return;
        }
        int mid = l + (r - l) / 2;
        if (x <= mid) {
            add(x, l, mid, 2 * n + 1);
        } else {
            add(x, mid + 1, r, 2 * n + 2);
        }
        tree[n] = (tree[2 * n + 1] & tree[2 * n + 2]);  // & two subtrees
        min = Math.min(min, Math.abs(tree[n] - target));
    }
}
