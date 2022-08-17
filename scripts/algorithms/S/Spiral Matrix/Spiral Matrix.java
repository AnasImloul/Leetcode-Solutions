class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
    int m = matrix.length, n = matrix[0].length;
    int upper_bound = 0, lower_bound = m - 1;
    int left_bound = 0, right_bound = n - 1;
    List<Integer> res = new LinkedList<>();
    // res.size() == m * n to go through the whole matrix
    while (res.size() < m * n) {
        if (upper_bound <= lower_bound) {
            // from left to right on the top
            for (int j = left_bound; j <= right_bound; j++) {
                res.add(matrix[upper_bound][j]);
            }
            // move the upper bound down
            upper_bound++;
        }
        
        if (left_bound <= right_bound) {
            // traveral from up to dwon on the right side
            for (int i = upper_bound; i <= lower_bound; i++) {
                res.add(matrix[i][right_bound]);
            }
            // move the right bound left
            right_bound--;
        }
        
        if (upper_bound <= lower_bound) {
            // traveral from rigth to left on the bottom side
            for (int j = right_bound; j >= left_bound; j--) {
                res.add(matrix[lower_bound][j]);
            }
            // move the lower bound up
            lower_bound--;
        }
        
        if (left_bound <= right_bound) {
            //traveral from down to up on the left side
            for (int i = lower_bound; i >= upper_bound; i--) {
                res.add(matrix[i][left_bound]);
            }
            // move the left bound rigth
            left_bound++;
        }
    }
    return res;
}
}
