// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 22.22%)

impl Solution {
    pub fn reverse_parentheses(s: String) -> String {
        let mut v = vec![String::new()];
        
        let mut i = 0;

        for c in s.chars() {
            if c == '(' {
                v.push(String::new());

                i += 1;
            } else if c == ')' {
                let t = v.pop().unwrap().chars().rev().collect::<String>();

                v[i - 1].push_str(&t);                

                i -= 1;
            } else {
                v[i].push(c);
            }
        }

        v.pop().unwrap()     
    }
}
