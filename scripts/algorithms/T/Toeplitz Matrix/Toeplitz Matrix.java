class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
          
        
        int n = matrix.length;
        int m = matrix[0].length;
        
        for(int i = 0; i < m; i++){
            int row = 0;
            int col = i;
            int e = matrix[row++][col++];
           while(row < n && col< m){
               if(e == matrix[row][col]){
                   row++;
                   col++;
               }else{
                   return false;
               }
           }  
        }
        
        for(int r = 1; r < n; r++){
            int row = r;
            int col = 0;
            int e =matrix[row++][col++];
            while(row < n && col < m){
                if(e == matrix[row][col]){
                    row++;
                    col++;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
}
