// Runtime: 2 ms (Top 86.17%) | Memory: 2.60 MB (Top 68.59%)

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut max_length = 0;
        let mut last_index = [0; 128];
        let mut start = 0;

        for (end, ch) in s.chars().enumerate() {
            start = start.max(last_index[ch as usize]);
            max_length = max_length.max(end - start + 1);
            last_index[ch as usize] = end + 1;
        }

        max_length as i32
    }
}
