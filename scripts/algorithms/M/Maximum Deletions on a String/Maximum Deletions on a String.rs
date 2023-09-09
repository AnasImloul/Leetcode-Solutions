// Runtime: 55 ms (Top 100.0%) | Memory: 2.04 MB (Top 50.0%)

impl Solution {
    pub fn delete_string(s: String) -> i32 {
        let s = s.as_bytes();
        let mut dp = vec![-1; s.len() + 1];
        dp[0] = 1;
        let mut max = 1;
        for i in 1..s.len() {
            let w = i - i.saturating_sub(s.len() - i);
            for j in 1..=w {
                if dp[i - j] != -1 && dp[i - j] >= dp[i] && s[i-j..i] == s[i..i+j] {
                    dp[i] = dp[i-j] + 1;
                    max = max.max(dp[i]);
                }
            }
        }
        max
    }
}