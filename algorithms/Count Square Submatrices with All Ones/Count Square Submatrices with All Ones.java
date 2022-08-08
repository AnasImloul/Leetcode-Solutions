class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] res = new int[m][n];
        
        for(int j=0; j<n; j++)
            res[0][j] = matrix[0][j];
        
        for(int i=0; i<m; i++)
            res[i][0] = matrix[i][0];
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 1){
                    res[i][j] = Math.min(res[i-1][j], Math.min(res[i][j-1], res[i-1][j-1])) + 1;
                }
                else
                    res[i][j] = 0;
            }
        }
        
        int sum = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum += res[i][j];
            }
        }
        
        return sum;
    }
}
