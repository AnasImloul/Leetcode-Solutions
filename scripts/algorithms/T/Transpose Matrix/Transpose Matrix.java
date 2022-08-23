// Runtime: 0 ms (Top 100.00%) | Memory: 43.1 MB (Top 92.66%)
class Solution {
    public int[][] transpose(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[][] trans = new int[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                trans[i][j] = matrix[j][i];
            }
        }

        return trans;
    }
}