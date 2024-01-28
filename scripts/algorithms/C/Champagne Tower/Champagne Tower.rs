// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 25.0%)

impl Solution {
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
        let mut dp = vec![vec![0.0; query_row as usize + 1]; query_row as usize + 1];
        dp[0][0] = poured as f64;

        for i in 1..dp.len() {
            for j in 0..=i {
                let l = *dp[i - 1].get(j - 1).unwrap_or(&0.0);
                let r = dp[i - 1][j];
                dp[i][j] = 0f64.max(l - 1.0) / 2.0 + 0f64.max(r - 1.0) / 2.0;
            }
        }
        1f64.min(dp[query_row as usize][query_glass as usize])
    }
}
