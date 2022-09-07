// Runtime: 0 ms (Top 100.00%) | Memory: 42.7 MB (Top 54.90%)
class Solution {
    public void swap(int[][] matrix, int n1, int m1, int n2, int m2) {
        int a = matrix[n1][m1];
        int temp = matrix[n2][m2];
        matrix[n2][m2] = a;
        matrix[n1][m1] = temp;
    }
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix, i,j, n-i-1, j);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                swap(matrix, i,j, j, i);
            }
        }
    }
}