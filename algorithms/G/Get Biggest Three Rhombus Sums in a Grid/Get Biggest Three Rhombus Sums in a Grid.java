class Solution {
    public int[] getBiggestThree(int[][] grid) {
        int end = Math.min(grid.length, grid[0].length);
        int maxThree[] = {0,0,0};
        for(int length=0; length<end; length++){
            searchBigThree(grid, maxThree, length);
        }
        
        Arrays.sort(maxThree);
        
        // If there are less than three distinct values, return all of them.
        if(maxThree[0] == 0){
            if(maxThree[1] == 0){
                return new int[]{maxThree[2]}; 
            }
            return new int[]{maxThree[2],maxThree[1]}; 
        }
        
        // reverse array
        maxThree[0] = maxThree[0]^maxThree[2];
        maxThree[2] = maxThree[0]^maxThree[2];
        maxThree[0] = maxThree[0]^maxThree[2];
        
        
        return maxThree;
    }
    
    void searchBigThree(int[][] grid, int[] maxThree, int length){
        int end = grid.length-(length==0?0: 2*length);
        int end1 = grid[0].length-(length);
        for(int start = 0; start<end; start++){
            for(int start1 = length; start1<end1; start1++){
                if(start+start1 >= length){
                    addToMaxThree(maxThree, getSum(grid, start, start1, length));
                }
            }
        }
    }
    
    /*
    get sum of edges of rhombus abcd
            a
           / \
          d   b
           \ /
            c
    
    */
    int getSum(int[][] grid, int i, int j, int length){
        if(length == 0){
            return grid[i][j];
        }
        
        int sum = 0;
        // edge ab
        for(int it=0; it<=length; it++){
            sum = sum + grid[i+it][j+it];
        }
        
        // edge ad
        for(int it=1; it<=length; it++){
            sum = sum + grid[i+it][j-it];
        }
        
        // edge dc
        for(int it=1; it<=length; it++){
            sum = sum + grid[i+length+it][j-length+it];
        }
        
        // edge bc
        for(int it=1; it<length; it++){
            sum = sum + grid[i+length+it][j+length-it];
        }
        
        return sum;
    }
    
    void addToMaxThree(int[] maxThree, int num){
        // Do not add duplicate entry
        if(maxThree[0] == num || maxThree[1] == num || maxThree[2] == num ){
            return;
        }
        
        Arrays.sort(maxThree);
        
        if(maxThree[0] < num){
            maxThree[0] = num;
        }
    } 
}
