// Runtime: 5 ms (Top 78.57%) | Memory: 2.30 MB (Top 92.86%)

impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let mut char_positions = [(usize::MAX, 0_usize); 26];

        for (i, b) in s.bytes().enumerate() {
            let bu = usize::from(b - b'a');
            char_positions[bu].0 = char_positions[bu].0.min(i);
            char_positions[bu].1 = i;
        }

        let bs = s.as_bytes();
        char_positions
            .into_iter()
            .filter(|(f, l)| f < l)
            .map(|(f, l)| {
                bs[f + 1..*l]
                    .iter()
                    .fold(0_u32, |set, c| set | (1 << (c - b'a')))
                    .count_ones() as i32
            })
            .sum()
    }
}
