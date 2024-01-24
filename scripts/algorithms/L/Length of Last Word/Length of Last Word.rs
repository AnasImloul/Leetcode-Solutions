// Runtime: 0 ms (Top 100.0%) | Memory: 2.00 MB (Top 81.84%)

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        s.trim_end()
            .chars()
            .rev()
            .take_while(|c| c.is_alphabetic())
            .count() as i32
    }
}
