// Runtime: 2 ms (Top 100.0%) | Memory: 2.02 MB (Top 100.0%)

impl Solution {
    pub fn is_valid(s: String) -> bool {

        let mut stack: Vec<[u8; 3]> = vec![[0, 0, 0]; 1];

        for byte in s.as_bytes() {
            let idx = (*byte - b'a') as usize;

            if stack.last().unwrap()[idx] == 1 {
                stack.push([0, 0, 0]);
            }

            let counts = stack.last_mut().unwrap();

            counts[idx] = 1;
            if counts[2] > counts[1] || counts[2] > counts[0] || counts[1] > counts[0] {
                return false
            } else if *counts == [1, 1, 1] {
                stack.pop();
                if stack.len() == 0 {
                    stack.push([0, 0, 0]);
                }
            }
        }

        stack.len() == 1 && stack[0] == [0, 0, 0]
    }
}