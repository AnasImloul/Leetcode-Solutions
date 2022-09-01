// Runtime: 12 ms (Top 94.21%) | Memory: 40.8 MB (Top 96.38%)
class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n*k) return 0;
        if (n == 1) return 1;

        int[][] dp = new int[n+1][n*k+1];
        for (int i = 1; i<= k; i++) {
            dp[1][i] = 1;
        }
        int mod = 1000000007;
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= i*k && j <= target; j++) {
                for (int x = 1; x <= k; x++) {
                    if (j-x >= 1) {
                        dp[i][j] += dp[i-1][j-x];
                        if (dp[i][j] >= mod) {
                            dp[i][j] %= mod;
                        }
                    }
                }
            }
        }
        return dp[n][target]%mod;
    }
}