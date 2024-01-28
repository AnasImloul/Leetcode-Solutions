// Runtime: 20 ms (Top 100.0%) | Memory: 3.30 MB (Top 66.67%)

impl Solution {
    pub fn max_moves(grid: Vec<Vec<i32>>) -> i32 {
        let mut dp = vec![vec![-1; grid[0].len()]; grid.len()];
        (0..grid.len())
         .map(|row| Self::traverse(&grid, row, 0, &mut dp))
         .max()
         .unwrap() - 1
    }

    fn traverse(grid: &[Vec<i32>], row: usize, col: usize, dp: &mut [Vec<i32>]) -> i32 {
        if dp[row][col] != -1 {
            return dp[row][col];
        }

        if col + 1 >= grid[0].len() {
            return 1;
        }

        let mut t = 0;
        if row > 0 && grid[row][col] < grid[row - 1][col + 1] {
            t = t.max(Self::traverse(grid, row - 1, col + 1, dp));
        }
        if grid[row][col] < grid[row][col + 1] {
            t = t.max(Self::traverse(grid, row, col + 1, dp));
        }
        if row + 1 < grid.len() && grid[row][col] < grid[row + 1][col + 1] {
            t = t.max(Self::traverse(grid, row + 1, col + 1, dp));
        }
        dp[row][col] = t + 1;
        dp[row][col]
    }
}
