// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 80.77%)

impl Solution {
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let mut dp = vec![0; (target + 1) as usize];
        dp[0] = 1;
        
        for i in 1..=target as usize {
            for &num in &nums {
                if i as i32 - num >= 0 {
                    dp[i] += dp[(i as i32 - num) as usize];
                }
            }
        }
        
        dp[target as usize]
    }
}
