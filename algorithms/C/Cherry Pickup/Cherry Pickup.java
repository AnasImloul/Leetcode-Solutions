class Solution {
    int max = 0;
    public int cherryPickup(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        if(m == 1 && n == 1)
            return grid[0][0];
        dfs(0, 0, m, n, grid, 0);
        return max;
    }
    public void dfs(int i, int j, int m, int n, int[][] grid, int ccsf){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == -1)
            return;
        if(i == m-1 && j == n-1){
            helper(i, j, m, n, grid, ccsf);
        }
        int cheeries = grid[i][j];
        grid[i][j] = 0;
        dfs(i+1, j, m, n, grid, ccsf+cheeries);
        dfs(i, j+1, m, n, grid, ccsf+cheeries);
        grid[i][j] = cheeries;
    }
    public void helper(int i, int j, int m, int n, int[][] grid, int ccsf){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == -1)
            return;
        if(i == 0 && j == 0){
            max = Math.max(max, ccsf);
            return;
        }
        int cheeries = grid[i][j];
        grid[i][j] = 0;
        helper(i-1, j, m, n, grid, ccsf+cheeries);
        helper(i, j-1, m, n, grid, ccsf+cheeries);
        grid[i][j] = cheeries;
    }
}
