class Solution {

    public int maxSumSubmatrix(int[][] matrix, int k) {
        final int m = matrix.length;
        if (m < 1) {
            throw new IllegalArgumentException("empty matrix - no rows");
        }
        final int n = matrix[0].length;
        if (n < 1) {
            throw new IllegalArgumentException("empty matrix - no columns");
        }
        // Let's make our bottom-right sum matrix wider and higher by 1 each, so we don't go out of range.
        // All of the values r >= m and c >= n should be 0 (and will default to 0 during array construction).
        final int[][] brsum = new int[m + 1][n + 1];
        // Build up from bottom right, bottom to top and right to left.
        for (int r = (m - 1); r >= 0; --r) {
            for (int c = (n - 1); c >= 0; --c) {
                final int val = matrix[r][c];
                // did we happen to find a 1x1 rectangle at (r, c) which sums to k?
                if (val == k) {
                    return val;
                }
                // Extend the sum: value + right + down - rightAndDown (because rightAndDown was added twice)
                brsum[r][c] = matrix[r][c] + brsum[r][c + 1] + brsum[r + 1][c] - brsum[r + 1][c + 1];
            }
        }
        // Now, we search.
        int maxSum = Integer.MIN_VALUE;
        for (int r0 = 0; r0 < m; ++r0) {
            for (int rf = r0; rf < m; ++rf) {
                final int rfp1 = rf + 1; // Let's avoid computing rf + 1 many times.
                for (int c0 = 0; c0 < n; ++c0) {
                    for (int cf = c0; cf < n; ++cf) {
                        final int cfp1 = cf + 1; // Let's avoid computing cf + 1 multiple times.
						// Compute the sum for this rectangle: complete - right - lower + lower_right.
                        final int sum = brsum[r0][c0] + brsum[rfp1][cfp1] - brsum[r0][cfp1] - brsum[rfp1][c0];
						// Did we happen to find a sum adding to k?  If not, did we find a larger sum less than k?
                        if (sum == k) {
                            return sum;
                        } else if (sum < k && sum > maxSum) {
                            maxSum = sum;
                        }
                    }
                }
            }
        }
        return maxSum;
    }

}
