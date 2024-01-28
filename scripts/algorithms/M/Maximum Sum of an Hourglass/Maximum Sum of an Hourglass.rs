// Runtime: 0 ms (Top 100.0%) | Memory: 2.40 MB (Top 25.0%)

impl Solution {
    pub fn max_sum(grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());
        let mut sum3: Vec<Vec<i32>> = vec![vec![0; n]; m];
        let mut center: Vec<Vec<i32>> = vec![vec![0; n]; m];
        let mut ans: i32 = 0;
        for j in 2..n {
            sum3[0][j] = grid[0][j] + grid[0][j - 1] + grid[0][j - 2];
        }
        for i in 1..m {
            for j in 1..n {
                if i>0 && j>=1 && j<=n-2{
                    center[i][j] = sum3[i-1][j+1] + grid[i][j];
                }
                if j >= 2 {
                    sum3[i][j] = grid[i][j] + grid[i][j - 1] + grid[i][j - 2];
                    if i >= 2 {
                        ans = ans.max(sum3[i][j] + center[i-1][j-1]);
                    }
                }
            }
        }
        ans
    }
}
