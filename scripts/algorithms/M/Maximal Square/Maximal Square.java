// Runtime: 5 ms (Top 98.27%) | Memory: 53.6 MB (Top 98.31%)
class Solution {
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];

        int max = 0;

        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - 48;
            if (matrix[i][0] == '1') max = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i] - 48;
            if (matrix[0][i] == '1') max = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    if (dp[i][j] > max) {
                        max = dp[i][j];
                    }
                }
            }
        }

        return max * max;
    }
}