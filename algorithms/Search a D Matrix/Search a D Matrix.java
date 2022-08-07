class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (target < matrix[0][0]) {
            return false;
        }
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i][0] > target | i == matrix.length - 1) {
                if (matrix[i][0] > target) {
                    i--;
                }
                for (int j = 0; j < matrix[i].length; j++) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
}
