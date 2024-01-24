// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 91.67%)

impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        let broken_hash = broken_letters
            .into_bytes()
            .iter()
            .fold([false; 26], |mut acc, &b| {
                acc[(b - b'a') as usize] = true;
                acc
            });

        text.split_ascii_whitespace()
            .filter(|&s| {
                s.as_bytes()
                    .iter()
                    .all(|&b| !broken_hash[(b - b'a') as usize])
            })
            .count() as _
    }
}
