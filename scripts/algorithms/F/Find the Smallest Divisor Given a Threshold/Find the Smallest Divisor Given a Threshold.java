// Runtime: 6 ms (Top 97.4%) | Memory: 46.77 MB (Top 83.7%)

class Solution {
    public int smallestDivisor(int[] a, int h) {
        int l = 1, r = a[0];
        for (int x : a) if (x > r) r = x;

        while (l < r) {
            int m = l + (r-l)/2;
            if (valid(a, m, h)) r = m;
            else l = m + 1;
        }

        return l;
    }

    private boolean valid(int[] a, int m, int h) {
        for (int x : a)
            if ((h -= (x + m-1)/m) < 0) return false;
        return true;
    }
}