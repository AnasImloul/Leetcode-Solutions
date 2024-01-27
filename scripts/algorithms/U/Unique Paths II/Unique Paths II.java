// Runtime: 0 ms (Top 100.0%) | Memory: 41.40 MB (Top 60.59%)

class Solution {
    public int uniquePathsWithObstacles(int[][] OG) {
        if (OG[0][0] == 1) return 0;
        int m = OG.length, n = OG[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (OG[i][j] == 1 || (i == 0 && j == 0)) continue;
                else dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
        return dp[m-1][n-1];
    }
}
