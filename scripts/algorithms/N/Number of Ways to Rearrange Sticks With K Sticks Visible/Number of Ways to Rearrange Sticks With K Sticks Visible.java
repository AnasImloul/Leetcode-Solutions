// Runtime: 368 ms (Top 16.85%) | Memory: 89.8 MB (Top 41.57%)
class Solution {
    public int rearrangeSticks(int n, int k) {
        final int MOD = 1_000_000_007;
        long[][] M = new long[k + 1][n + 1];
        M[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                M[i][j] = ((j - 1) * M[i][j - 1] % MOD + M[i - 1][j - 1]) % MOD;
            }
        }
        return (int) M[k][n];
    }
}