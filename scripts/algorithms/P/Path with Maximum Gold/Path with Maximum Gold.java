class Solution {
    
    public static int[][] copy(int[][] src) {
        if (src == null) {
            return null;
        }
 
        return Arrays.stream(src).map(int[]::clone).toArray(int[][]::new);
    }
    
    static int helper(int[][] grid, int row, int col, int total){
        if(row < 0 || row >= grid.length || col < 0 || col >= grid[0].length){
            return total;
        }
        
        if(grid[row][col] == 0){
            return 0;
        }
        
        if(grid[row][col] == -1){
            return 0;
        }
        
        total += grid[row][col];
        int temp = grid[row][col];
        grid[row][col] = -1;
        total = Math.max(Math.max(Math.max(Math.max(helper(grid, row + 1, col, total), 
                                                    helper(grid, row, col + 1, total)), 
                                           helper(grid, row, col - 1, total)), 
                                  helper(grid, row - 1, col, total)), 
                         total);
        
        grid[row][col] = temp;
        
        return total;
    }
    
    public int getMaximumGold(int[][] grid) {
        
        int currMax = Integer.MIN_VALUE;
        int[][] tempGrid;
        
        
        for(int i = 0; i < grid.length; i++){  
            for(int j = 0; j < grid[0].length; j++){
                tempGrid = copy(grid);
                currMax = Math.max(helper(tempGrid, i, j, 0), currMax);
            }
        }
        
        return currMax;
    }
}
