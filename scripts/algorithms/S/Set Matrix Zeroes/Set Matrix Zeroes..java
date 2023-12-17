// Runtime: 2 ms (Top 25.0%) | Memory: 44.70 MB (Top 37.39%)

class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> row = new HashSet<>();
        Set<Integer> col = new HashSet<>();
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    row.add(i);
                    col.add(j);
                }
            }
        }
        for(int r : row){
            for(int i = 0; i < matrix[0].length; i++){
                matrix[r][i] = 0;
            }
        }
        for(int c : col){
            for(int i = 0; i < matrix.length; i++){
                matrix[i][c] = 0;
            }
        }
    }
}
