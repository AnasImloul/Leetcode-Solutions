// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 21.69%)

use std::cmp::{max};

impl Solution {
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        
        let mut firsts = [None; 26];
        let mut max_len = -1;

        for (i, char) in s.chars().enumerate() {
            let i = i as i32;
            let j = (char as u8 - b'a') as usize;
            match firsts[j] {
                Some(first) => {
                    max_len = max(i - first, max_len);
                }
                None => {
                    firsts[j] = Some(i + 1);
                }
            }
        }

        max_len
    }
}
