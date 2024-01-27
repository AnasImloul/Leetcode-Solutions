// Runtime: 25 ms (Top 100.0%) | Memory: 3.80 MB (Top 100.0%)

impl Solution {
    pub fn count_paths(grid: Vec<Vec<i32>>) -> i32 {
        let mut dp = vec![vec![0; grid[0].len()]; grid.len()];

        let mut count = 0;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                count += search(&grid, i, j, &mut dp);
                count %= M;
            }
        }
        return count;
    }
}

const M: i32 = 1_000_000_000 + 7;

fn search(grid: &Vec<Vec<i32>>, i: usize, j: usize, dp: &mut Vec<Vec<i32>>) -> i32 {
    let count = dp[i][j];
    if count > 0 {
        return count;
    }

    let v = grid[i][j];

    let mut count = 1;

    if i+1 != grid.len() && v < grid[i+1][j] {
        count += search(grid, i+1, j, dp);
        count %= M;
    }
    if j+1 != grid[i].len() && v < grid[i][j+1] {
        count += search(grid, i, j+1, dp);
        count %= M;
    }
    if i != 0 && v < grid[i-1][j] {
        count += search(grid, i-1, j, dp);
        count %= M;
    }
    if j != 0 && v < grid[i][j-1] {
        count += search(grid, i, j-1, dp);
        count %= M;
    }
    dp[i][j] = count;

    return count;
}
