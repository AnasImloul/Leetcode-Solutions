// Runtime: 45 ms (Top 33.3%) | Memory: 8.09 MB (Top 33.3%)

impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let s = s.chars().into_iter().collect::<Vec<char>>();
        let n = s.len();
        let mut result = vec!['a';n+spaces.len()];
        for i in 0..spaces.len() {
            result[spaces[i] as usize + i] = ' ';
        } 

        let mut i = 0;
        for ci in 0..result.len() {
            if result[ci] != ' ' {
                result[ci] = s[i];
                i += 1;
            }
        }
        result.into_iter().map(|v| v.to_string()).collect::<String>()
    }
}