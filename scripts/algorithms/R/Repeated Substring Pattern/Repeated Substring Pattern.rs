// Runtime: 0 ms (Top 100.0%) | Memory: 2.00 MB (Top 94.32%)

impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {
        for i in 0..s.len()/2 {
            let n = s.len();
            if n as u32 % (i as u32 + 1) != 0 {
                continue;
            }
            let sub = &s[..i+1];
            let mut rep = true;
            for j in 1..n/sub.len() {
                let a = sub.len() * j;
                if s[a..a+sub.len()] != *sub {
                    rep = false;
                    break;
                }
            }
            if rep == true {
                return true;
            }
        }
        return false;
    }
}
