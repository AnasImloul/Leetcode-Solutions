class Solution {
    long[][] dp;
    int mod = 1_000_000_007;
    public int countPaths(int[][] grid) {
        dp = new long[grid.length][grid[0].length];
        long sum=0L;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                sum = (sum + dfs(grid,i,j,0)) % mod;
            }
        }
        return (int)sum;
    }
    long dfs(int[][] grid,int i,int j,int pre){
        if(i<0||j<0||i>=grid.length||j>=grid[0].length) return 0;
        if(grid[i][j]<=pre) return 0;
        if(dp[i][j]>0) return dp[i][j];
        long a = dfs(grid,i+1,j,grid[i][j]);
        long b = dfs(grid,i,j+1,grid[i][j]);
        long c = dfs(grid,i-1,j,grid[i][j]);
        long d = dfs(grid,i,j-1,grid[i][j]);
        dp[i][j] = (1+a+b+c+d)%mod;
        return dp[i][j];
    }
}
