// Runtime: 4 ms (Top 35.60%) | Memory: 47.1 MB (Top 38.97%)
class Solution {
    boolean isClosed = true;
    public int closedIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int count = 0;

        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                isClosed = true;
                if(grid[i][j] == 0){
                    dfs(grid, i, j);

                    if(isClosed){
                        count++;
                    }
                }
            }
        }

        return count;
    }

    public void dfs(int[][] grid, int i, int j){
        if(i<0 || j<0 || i> grid.length-1 || j> grid[0].length-1 || grid[i][j] != 0) return;

         grid[i][j] = 1; // to mark as visited

        if(i == 0 || j == 0 || i == grid.length -1 || j == grid[0].length - 1) isClosed = false;

        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
    }
}