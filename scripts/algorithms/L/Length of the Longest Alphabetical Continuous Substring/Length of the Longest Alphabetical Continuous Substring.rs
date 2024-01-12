// Runtime: 0 ms (Top 100.0%) | Memory: 2.40 MB (Top 50.0%)

impl Solution {
    pub fn longest_continuous_substring(s: String) -> i32 {
        let mut max = 1;
        let mut curr = 1;
        let s = s.as_bytes();
        for i in 1..s.len() {
            if s[i] == s[i-1] + 1 {
                curr += 1;
            } else {
                curr = 1;
            }
            max = max.max(curr);
        }
        max as _
    }
}
