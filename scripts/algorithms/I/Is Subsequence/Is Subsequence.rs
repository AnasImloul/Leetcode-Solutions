// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 49.59%)

impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut iter = t.chars();
        for c in s.chars() {
          match iter.find(|&p| p == c) {
            Some(_) => (),
            None => return false
          }
        }
        true
    }
}
