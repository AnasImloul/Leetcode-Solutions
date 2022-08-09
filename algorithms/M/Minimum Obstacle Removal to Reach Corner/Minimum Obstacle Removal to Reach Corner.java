
class Solution {
    int [][]grid;
    int n,m;
    boolean [][]seen;
    int []dx = new int[]{0,0,1,-1};
    int []dy = new int[]{1,-1,0,0};
    int [][]dp;
    int finalres;
    private boolean isValid(int i, int j) {
        return Math.min(i,j)>=0 && i<n && j<m && !seen[i][j];
    }
    
    private int solve(int i, int j, int cnt) {
        if(cnt>=finalres) return finalres;
        if(i == n-1 && j == m-1) {
            return cnt;
        }
        if(dp[i][j]!=Integer.MAX_VALUE) return dp[i][j];
        int res = n*m+1;
        seen[i][j]=true;
        for(int k=0;k<4;k++) {
            int newI = i+dx[k], newJ = j+dy[k];
            if(isValid(newI, newJ)) {
                res = Math.min(res, solve(newI, newJ, cnt+grid[i][j]));
            }
        }
        seen[i][j]=false;
        return dp[i][j]=Math.min(dp[i][j], res);
    }
    
    public int minimumObstacles(int[][] grid) {
        this.grid = grid;
        this.n = grid.length;
        this.m = grid[0].length;
        this.seen = new boolean[n][m];
        dp = new int[n][m];
        finalres = n*m+1;
        for(int []row:dp) Arrays.fill(row, Integer.MAX_VALUE);
        return solve(0,0,0);
    }
}
