// Runtime: 18 ms (Top 85.2%) | Memory: 60.07 MB (Top 40.7%)

class Solution {
    public int minCapability(int[] a, int k) {
        int n = a.length;
        int l = a[0], r = a[0]; // left and right bound for binary search

        for (int x : a) {
            l = Math.min(l, x);
            r = Math.max(r, x);
        }

        while (l < r) { // straight forward binary search logic for min valid value
            int m = l + (r-l)/2;
            if (valid(a, m, k)) r = m;
            else l = m + 1;
        }

        return l; // when search ends l == r, could return either one
    }

    private boolean valid(int[] a, int m, int k) {
        for (int i = 0; i < a.length; ) {
            if (a[i] <= m) { // will hit ith house, GREEDY
                if (--k == 0) return true; // hit enough of k houses
                i += 2; // if this one is taken, stip next
            } else i++; // if this one is not taken, move on to next
        }

        return false; // fail to hit k houses
    }
}