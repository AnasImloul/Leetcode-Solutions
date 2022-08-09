class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> luckyNums = new ArrayList();
        int n = matrix.length;
        int m = matrix[0].length;
        
        for(int[] row : matrix){
            int min = row[0];
            int index = 0;
            boolean lucky = true;
            for(int col = 0; col < m; col++){
                if(min > row[col]){
                    min = row[col];
                    index = col;
                }
            }
            
            for(int r = 0; r < n; r++){
                if(min < matrix[r][index]){
                    lucky = false;
                    break;
                }
            }
            if(lucky){
                luckyNums.add(min);
            }
            
        }
        
        return luckyNums;
        
    }
}
