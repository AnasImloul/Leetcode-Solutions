// Runtime: 343 ms (Top 33.3%) | Memory: 6.26 MB (Top 33.3%)

use std::collections::HashMap;

impl Solution {
    pub fn min_cost(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut trimmed = vec![vec![0; n + 1]; n + 1];
        for i in 1..=n {
            let mut count = HashMap::new();
            for j in i..=n {
                trimmed[i][j] = trimmed[i][j - 1];
                let c = count.entry(nums[j - 1]).or_insert(0);
                *c += 1;
                if *c == 2 {
                    trimmed[i][j] += 2;
                } else if *c > 2 {
                    trimmed[i][j] += 1;
                }
            }
        }
        let mut dp = vec![i32::MAX; n + 1];
        dp[0] = 0;
        for i in 1..=n {
            for j in 0..i {
                dp[i] = dp[i].min(dp[j] + trimmed[j + 1][i] + k);
            }
        }
        dp[n]
    }
}