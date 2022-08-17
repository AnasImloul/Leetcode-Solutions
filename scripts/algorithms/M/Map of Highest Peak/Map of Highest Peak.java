class Solution {
    
    static int[][] DIRECTION = new int[][]{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int rows;
    int cols;
    int[][] isWater;

    
    public int[][] highestPeak(int[][] isWater) {
        this.isWater = isWater;
        rows = isWater.length;
        cols = isWater[0].length;
        

        int[][] heightCells = new int[rows][cols];
        
        //store the coordinate of water cell
        Queue<int[]> queue = new LinkedList();
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(isWater[r][c] == 1){
                    
                    //mark as water
                    heightCells[r][c] = 0;
                    
                    //add water coordinate
                    queue.add(new int[]{r, c});
                } else{
                    //mark default value for land
                    heightCells[r][c] = -1;  
                }
            }
        }

        
        /*
        * Approach
        * 1. start from every water source, 
             update their neighbor height
        * 2. add each neighbours which was not processed earlier
          3. do it every cell is processed
        */
        bfs(queue, heightCells);
        
        
        return heightCells;
    }
    
    private void bfs(Queue<int[]> queue, int[][] heightCells){
        
        while(!queue.isEmpty()){
            int[] cell = queue.remove();
 
            //increment height of neighbor cell in all 4 direction 
            //e.g, left, right, up, down
            for(int[] dir : DIRECTION){
                
                int newRow = cell[0] + dir[0];
                int newCol = cell[1] + dir[1]; 
                
                //check new coordinate of cell inside the grid or not
                if(!isInsideGrid(newRow, newCol)) continue;
                
                //check already handled
                if(heightCells[newRow][newCol] != -1) continue;

                //increament, 
                heightCells[newRow][newCol] =  heightCells[cell[0]][cell[1]] + 1;
                
                //to handle the neighbour of this new cell
                queue.add(new int[]{newRow, newCol});
            }
        
        }
    }
    
    private boolean isInsideGrid(int row, int col){
        return row >= 0 && row < rows && col >= 0 && col < cols;
    } 
}
