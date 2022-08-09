class Solution {
    public int projectionArea(int[][] grid) {
        int totalArea = 0;
        
        
        for(int[] row : grid){
            int max = row[0];
            for(int c : row){
                if(max < c){
                    max = c;
                }if(c != 0){
                    totalArea += 1;
                }
                
            }
            totalArea += max;
        }
        
        for(int c = 0; c < grid[0].length; c++){
            int max = grid[0][c];
            for(int row = 0; row  <  grid.length; row++){
                if(max < grid[row][c]){
                    
                    max = grid[row][c];
                }
            }
            totalArea += max;
            }
        return totalArea;
    }
}
