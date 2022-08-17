class Solution {
    static int [][]dirs={{-1,0},{0,1},{0,-1},{1,0}};
    public void connectedComponents(int[][] grid, int i, int j, boolean[][] visited) {
        
        visited[i][j] = true;
        for(int d=0;d<4;d++){
            int r=i+dirs[d][0];
            int c=j+dirs[d][1];
            
            if(r>=0 && r<grid.length && c>=0 && c<grid[0].length && grid[r][c]==1 && visited[r][c]==false){
                connectedComponents(grid,r,c,visited);
            }
        }
    }

    public int numIslands(int[][] grid) {
        int islandCount = 0;
        boolean vis[][] = new boolean[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1 && vis[i][j] == false) {
                    islandCount++;
                    connectedComponents(grid, i, j, vis);
                }
            }
        }

        return islandCount;
    }

    public int minDays(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        //if more than 1 island is there then the graph is already disconnected
        if (numIslands(grid) > 1) {
            return 0;
        }

        //check for all 1's remove it and if there is more than 1 island then return 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;

                    if (numIslands(grid) != 1) {
                        return 1;
                    }

                    //recorrect it while backtracking
                    grid[i][j] = 1;
                }
            }
        }

        //else we need min 2 removal
        return 2;
    }
}
