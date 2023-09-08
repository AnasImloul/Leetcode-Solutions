// Runtime: 2 ms (Top 98.1%) | Memory: 45.96 MB (Top 86.5%)

/**
 * Simulate Diagonal Order Traversal
 *
 * r+c determines which diagonal you are on. For ex: [2,0],[1,1],[0,2] are all
 * on same diagonal with r+c =2. If you check the directions of diagonals, first
 * diagonal is up, second diagonal is down, third one is up and so on..
 * Therefore (r+c)%2 simply determines direction. Even is UP direction. Odd is
 * DOWN direction.
 *
 * Time Complexity: O(M*N)
 *
 * Space Complexity: O(1) without considering result space.
 *
 * M = Number of rows. N = Number of columns.
 */
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null) {
            throw new IllegalArgumentException("Input matrix is null");
        }
        if (matrix.length == 0 || matrix[0].length == 0) {
            return new int[0];
        }

        int rows = matrix.length;
        int cols = matrix[0].length;
        int[] result = new int[rows * cols];
        int r = 0;
        int c = 0;

        for (int i = 0; i < result.length; i++) {
            result[i] = matrix[r][c];
            if ((r + c) % 2 == 0) { // Move Up
                if (c == cols - 1) {
                    // Reached last column. Now move to below cell in the same column.
                    // This condition needs to be checked first due to top right corner cell.
                    r++;
                } else if (r == 0) {
                    // Reached first row. Now move to next cell in the same row.
                    c++;
                } else {
                    // Somewhere in middle. Keep going up diagonally.
                    r--;
                    c++;
                }
            } else { // Move Down
                if (r == rows - 1) {
                    // Reached last row. Now move to next cell in same row.
                    // This condition needs to be checked first due to bottom left corner cell.
                    c++;
                } else if (c == 0) {
                    // Reached first columns. Now move to below cell in the same column.
                    r++;
                } else {
                    // Somewhere in middle. Keep going down diagonally.
                    r++;
                    c--;
                }
            }
        }

        return result;
    }
}