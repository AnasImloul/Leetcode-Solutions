// Greedy Min Row Col Solution
// Time complexity: O(MN)
// Space complexity: O(MN)
class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        final int M = rowSum.length, N = colSum.length;
        int[][] matrix = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = Math.min(rowSum[i], colSum[j]);
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        return matrix;
    }
}
