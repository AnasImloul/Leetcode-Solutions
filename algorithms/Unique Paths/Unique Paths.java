class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                dp[i][j] = -1;
            }
        }
        
        return helper(m, 0, n, 0, dp);
    }
    
    private int helper(int m, int i, int n, int j, int[][] dp) {
        if(i == m || j == n) {
            return 0;
        }
        
        if(i == m-1 && j == n-1) {
            dp[i][j] = 1;
        }
        
        if(dp[i][j] == -1) {
            dp[i][j] = helper(m, i+1, n, j, dp) + helper(m, i, n, j+1, dp);
        }
        
        return dp[i][j];
    }
}