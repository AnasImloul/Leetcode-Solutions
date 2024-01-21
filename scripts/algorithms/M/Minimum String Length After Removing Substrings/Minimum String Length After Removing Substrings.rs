// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 20.0%)

impl Solution {
    pub fn min_length(s: String) -> i32 {

        let mut stack: Vec<&char> = Vec::new();
        let mut s_chars: Vec<char> = s.chars().collect::<Vec<char>>();

        for i in 0..s_chars.len() {

            if stack.len() > 0 && (*stack[stack.len() -1] == 'C' && s_chars[i] == 'D' || *stack[stack.len() -1] == 'A' && s_chars[i] == 'B'){
                stack.pop();

            } else {
                stack.push(&s_chars[i]);
            }

        }

        stack.len() as i32
    }
}
