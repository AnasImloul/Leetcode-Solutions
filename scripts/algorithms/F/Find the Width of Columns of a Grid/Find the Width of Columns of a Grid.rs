// Runtime: 4 ms (Top 31.58%) | Memory: 2.30 MB (Top 73.68%)

impl Solution {
    pub fn find_column_width(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = vec![0; grid[0].len()];
        for row in grid {
            for (i, col) in row.iter().enumerate() {
                ans[i] = ans[i].max(col.to_string().len() as i32);
            }
        }
        ans
    }
}
