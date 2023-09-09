// Runtime: 1 ms (Top 90.9%) | Memory: 2.02 MB (Top 100.0%)

impl Solution {
    pub fn max_power(s: String) -> i32 {
        s.into_bytes()
            .windows(2)
            .scan(1, |s, x| {
                *s = if x[0] == x[1] { *s + 1 } else { 1 };
                Some(*s)
            })
            .max()
            .unwrap_or(1)
    }
}