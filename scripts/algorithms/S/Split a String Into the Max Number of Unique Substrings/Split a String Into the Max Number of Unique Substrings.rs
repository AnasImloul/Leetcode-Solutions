// Runtime: 64 ms (Top 100.0%) | Memory: 2.10 MB (Top 100.0%)

use std::collections::HashSet;

impl Solution {
    pub fn max_unique_split(s: String) -> i32 {
        let mut combos = HashSet::new();
        let mut max = 0;
        let chars: Vec<String> = s.chars().map(|c| c.to_string()).collect();
        Self::helper(&mut combos, &chars, &mut max);

        max as i32
    }

    fn helper(combos: &mut HashSet<String>, chars: &[String], max: &mut usize) {
        if !chars.is_empty() {
            for i in 0..chars.len() {
                let mut substr = chars[0..i + 1]
                    .iter()
                    .fold(String::with_capacity(i), |mut new_str, s| {
                        new_str.push_str(s);
                        new_str
                    });
                if !combos.contains(&substr) {
                    combos.insert(substr.clone());
                    Self::helper(combos, &chars[i + 1..], max);
                    combos.remove(&substr);
                }
            }
        } else {
            if combos.len() > *max {
                *max = combos.len();
            }
        }
    }
}
