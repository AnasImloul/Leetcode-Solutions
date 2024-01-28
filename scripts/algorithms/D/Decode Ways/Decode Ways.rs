// Runtime: 0 ms (Top 100.0%) | Memory: 2.00 MB (Top 99.6%)

impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let mut prev = 1;
        let mut prev_2 = 0;
        let mut prev_ch = 'X';
        let mut cur = 1;
        for ch in s.chars().rev() {
            if ch == '1' || (ch == '2' && prev_ch as u8 <= '6' as u8) {
                cur = prev_2 + prev;
            }
            else if ch == '0' {
                cur = 0;
            }
            prev_2 = prev;
            prev = cur;
            prev_ch = ch;
        }
        cur as _
    }
}
