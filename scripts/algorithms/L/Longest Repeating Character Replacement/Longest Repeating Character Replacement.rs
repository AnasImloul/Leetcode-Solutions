// Runtime: 1 ms (Top 91.75%) | Memory: 2.10 MB (Top 57.73%)

use std::cmp::max;
const NUM_ALPHA : usize = 26;

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut counts : [usize;NUM_ALPHA] = [0;NUM_ALPHA];
        let s = s.chars().collect::<Vec<_>>();
        (0..s.len()).fold((0, 0, 0), |(res_len, mut maxf, mut l), r| {
            counts[(s[r] as u8 - b'A') as usize] += 1;
            maxf = max(maxf, counts[(s[r] as u8 - b'A') as usize]);
            if (r - l + 1 ) - maxf > k as usize {
                counts[(s[l] as u8 - b'A') as usize] -= 1;
                l += 1;
            }
            (max(res_len, r - l  + 1), maxf, l)
        }).0 as i32
    }
}
