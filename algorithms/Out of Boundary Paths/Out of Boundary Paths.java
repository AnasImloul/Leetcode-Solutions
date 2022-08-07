class Solution {
    int[][][] dp;
    int mod = 1000000007;
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = new int[m][n][maxMove + 1];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k <= maxMove; k++)
                    dp[i][j][k] = -1;
        return count(m, n, maxMove, startRow, startColumn) % mod;
    }
    public int count(int m, int n, int move, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return 1;
        if (move <= 0)
            return 0;
        if (dp[r][c][move] != -1)
            return dp[r][c][move] % mod;
        dp[r][c][move] = ((count(m, n, move - 1, r + 1, c) % mod + count (m, n, move - 1, r - 1, c) % mod) % mod + (count (m, n, move - 1, r, c + 1) % mod + count(m, n, move - 1, r, c - 1) % mod) % mod ) % mod;
        return dp[r][c][move] % mod;
    }
}
