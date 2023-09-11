// Runtime: 7 ms (Top 46.1%) | Memory: 2.42 MB (Top 19.2%)

impl Solution {
    pub fn is_scramble(s1: String, s2: String) -> bool {
        let n = s1.len();
        let (s1, s2) = (s1.as_bytes(), s2.as_bytes());
        let mut dp = vec![vec![vec![false; n]; n]; n + 1];
        for i in 0..n {
            for j in 0..n {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        for len in 2..=n {
            for i in 0..(n + 1 - len) {
                for j in 0..(n + 1 - len) {
                    let mut is_scrambled = dp[len][i][j];
                    for new_len in 1..len {
                        let dp1 = &dp[new_len][i];
                        let dp2 = &dp[len - new_len][i + new_len];
                        is_scrambled |= dp1[j] && dp2[j + new_len];
                        is_scrambled |= dp1[j + len - new_len] && dp2[j];
                    }
                    dp[len][i][j] = is_scrambled;
                }
            }
        }

        dp[n][0][0]
    }
}