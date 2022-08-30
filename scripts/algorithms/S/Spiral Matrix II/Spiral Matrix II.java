// Runtime: 0 ms (Top 100.00%) | Memory: 41.9 MB (Top 69.11%)
class Solution {
    public int[][] generateMatrix(int n) {
        int startingRow = 0;
        int endingRow = n-1;
        int startingCol = 0;
        int endingCol = n-1;

        int total = n*n;
        int element = 1;
        int[][] matrix = new int[n][n];

        while(element<=total){

        for(int i = startingCol; element<=total && i<=endingCol; i++){
            matrix[startingRow][i] = element;
            element++;
        }
        startingRow++;

        for(int i = startingRow; element<=total && i<=endingRow; i++){
            matrix[i][endingCol] = element;
            element++;
        }
        endingCol--;

        for(int i = endingCol; element<=total && i>=startingCol; i--){
            matrix[endingRow][i] = element;
            element++;
        }
        endingRow--;

        for(int i = endingRow; element<=total && i>=startingRow; i--){
            matrix[i][startingCol] = element;
            element++;
        }
        startingCol++;

        }

        return matrix;
    }
}