// Runtime: 26 ms (Top 75.0%) | Memory: 2.80 MB (Top 100.0%)

impl Solution {
    pub fn count_special_subsequences(nums: Vec<i32>) -> i32 {
        let mut dp = vec![0, 0, 0];
        let mod_ = 1_000_000_007;
        for &a in nums.iter() {
            let a = a as usize;
            dp[a] = ((dp[a] + dp[a]) % mod_ + (if a > 0 { dp[a - 1] } else { 1 })) % mod_;
        }
        dp[2]
    }
}
