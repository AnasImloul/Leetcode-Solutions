// Runtime: 11 ms (Top 84.7%) | Memory: 57.45 MB (Top 26.3%)

class Solution {
    int[][] dirs = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};

    public int[] hitBricks(int[][] grid, int[][] hits) {
        //marking all the hits that has a brick with -1
        for(int i=0;i<hits.length;i++)
            if(grid[hits[i][0]][hits[i][1]] == 1)
                grid[hits[i][0]][hits[i][1]] = -1;
        
        //marking all the stable bricks
        for(int i=0;i<grid[0].length;i++)
            markAndCountStableBricks(grid, 0, i);
        
        int[] res = new int[hits.length];
        //looping over hits array backwards and restoring bricks
        for(int i=hits.length-1;i>=0;i--){
            int row = hits[i][0];
            int col = hits[i][1];
            
            //hit is at empty space so continue
            if(grid[row][col] == 0)
                continue;
            
            //marking it with 1, this signifies that a brick is present in an unstable state and will be restored in the future
            grid[row][col] = 1;
            // checking brick stability, if it's unstable no need to visit the neighbours
            if(!isStable(grid, row, col))
                continue;
			
			//So now as our brick is stable we can restore all the bricks connected to it
            //mark all the unstable bricks as stable and get the count
            res[i] = markAndCountStableBricks(grid, hits[i][0], hits[i][1])-1; //Subtracting 1 from the total count, as we don't wanna include the starting restored brick
        }
        
        return res;
    }
    
    private int markAndCountStableBricks(int[][] grid, int row, int col){
        if(grid[row][col] == 0 || grid[row][col] == -1)
            return 0;
        
        grid[row][col] = 2;
        int stableBricks = 1;
        for(int[] dir:dirs){
            int r = row+dir[0];
            int c = col+dir[1];
            
            if(r < 0 || r >= grid.length || c < 0 || c >= grid[0].length)
                continue;
            
            if(grid[r][c] == 0 || grid[r][c] == -1 || grid[r][c] == 2)
                continue;
            
            stableBricks += markAndCountStableBricks(grid, r, c);
        }
        
        return stableBricks;
    }
    
    private boolean isStable(int[][] grid, int row, int col){
        if(row == 0)
            return true;
        
        for(int[] dir:dirs){
            int r = row+dir[0];
            int c = col+dir[1];
            
            if(r < 0 || r >= grid.length || c < 0 || c >= grid[0].length)
                continue;
            
            if(grid[r][c] == 2)
                return true;
        }
        
        return false;
    }
}