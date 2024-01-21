// Runtime: 19 ms (Top 79.76%) | Memory: 9.40 MB (Top 70.24%)

use std::cmp;

impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut dp = vec![vec![0; cols + 1]; rows + 1];
        let mut max_len: i32 = 0;

        for row in 1..=rows {
            for col in 1..=cols {
                if matrix[row - 1][col - 1] == '1' {
                    dp[row][col] = 1 + cmp::min(
                        cmp::min(dp[row - 1][col - 1], dp[row - 1][col]),
                        dp[row][col - 1],
                    );
                    max_len = cmp::max(max_len, dp[row][col] as i32);
                }
            }
        }

        max_len * max_len
    }
}
