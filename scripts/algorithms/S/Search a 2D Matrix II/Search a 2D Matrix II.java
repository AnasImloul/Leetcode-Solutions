// Runtime: 14 ms (Top 30.54%) | Memory: 57.2 MB (Top 69.94%)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int lo = 0, hi = rows;
        while(lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid][0] <= target) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        int[] prospect;
        for (int i = 0; i <= lo; i++) {
            prospect = matrix[i];
            int l = 0;
            int h = cols;
            while (l + 1 < h) {
                int mid = l + (h - l) / 2;
                if (prospect[mid] <= target) {
                    l = mid;
                } else {
                    h = mid;
                }
            }
            if (prospect[l] == target) {
                return true;
            }
        }
        return false;
    }
}