// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 83.33%)

impl Solution {
    pub fn length_longest_path(input: String) -> i32 {
        let split: Vec<&str> = input.split('\n').collect();

        let mut stack: Vec<(usize, &str)> = vec![];
        let mut ans = 0;

        for s in split {
            let mut lvl = 0;
            for ch in s.chars() {
                if ch == '\t' {
                    lvl += 1;
                } else {
                    break;
                }
            }
            let fname = &s[(lvl as usize)..];

            while stack.len() > 0 && stack[stack.len() - 1].0 >= lvl {
                stack.pop();
            }
            stack.push((lvl, fname.clone()));

            if fname.contains('.') {
                let v = stack
                    .clone()
                    .into_iter()
                    .map(|(_, s)| s.clone().to_string())
                    .collect::<Vec<String>>()
                    .join("/");
                    
                ans = ans.max(v.len() as i32);
            }
        }

        ans
    }
}
