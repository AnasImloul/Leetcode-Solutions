class Solution {
    private static final int p = 1_000_000_007;

    public int numberOfCombinations(String num) {
        int n = num.length();
        if (num.charAt(0) == '0') return 0;
        if (n == 1) return 1;
        long[] prev = new long[n + 1], next = new long[n + 1], tmp;
        prev[0] = 1;
        next[0] = 1;

        for (int d = 1; d <= n; d++) {
            System.arraycopy(prev, 1, next, 1, n);
            for (int j1 = 0, i1 = j1 - d, j2 = j1 + d; j2 <= n; j1++, j2++, i1++) {
                if (num.charAt(j1) != '0') {
                    if (i1 < 0 || num.charAt(i1) != '0' && ok(num, i1, j1, d)) next[j2] += next[j1];
                    else next[j2] += prev[j1];
                    if (next[j2] >= p) next[j2] -= p;
                }
            }
            tmp = prev;
            prev = next;
            next = tmp;
        }
        return (int) prev[n];
    }

    private static boolean ok(String num, int start1, int start2, int len) {
        while (len-- > 0) {
            char c1 = num.charAt(start1++), c2 = num.charAt(start2++);
            if (c1 > c2) return false;
            if (c1 < c2) return true;
        }
        return true;
    }
}
