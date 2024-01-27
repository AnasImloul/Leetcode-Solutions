// Runtime: 6 ms (Top 100.0%) | Memory: 2.30 MB (Top 25.0%)

use std::collections::HashMap;

impl Solution {
    pub fn execute_instructions(n: i32, start_pos: Vec<i32>, s: String) -> Vec<i32> {
        let mut row_map: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut col_map: HashMap<i32, Vec<i32>> = HashMap::new();
        row_map.insert(0, vec![0]);
        col_map.insert(0, vec![0]);
        let mut x = 0;
        let mut y = 0;
        let mut ans = vec![i32::MIN; s.len()];
        for i in 0..=s.len() {
            let v = if i == s.len() {
                row_map.drain()
                    .chain(col_map.drain())
                    .flat_map(|(_, v)| v)
                    .collect()
            }
            else {
                match s.as_bytes()[i] {
                    b'U' => {
                        x -= 1;
                        row_map.remove(&(x + start_pos[0] + 1)).unwrap_or(Vec::new())
                    }
                    b'D' => {
                        x += 1;
                        row_map.remove(&(x + start_pos[0] - n)).unwrap_or(Vec::new())
                    }
                    b'L' => {
                        y -= 1;
                        col_map.remove(&(y + start_pos[1] + 1)).unwrap_or(Vec::new())
                    }
                    b'R' => {
                        y += 1;
                        col_map.remove(&(y + start_pos[1] - n)).unwrap_or(Vec::new())
                    }
                    _ => unreachable!(),
                }
            };
            if i < s.len() - 1 {
                row_map.entry(x).or_insert(Vec::new()).push(i as i32 + 1);
                col_map.entry(y).or_insert(Vec::new()).push(i as i32 + 1);
            }
            for j in v.into_iter() {
                if ans[j as usize] == i32::MIN {
                    ans[j as usize] = i as i32 - j;
                }
            }
        }
        ans
    }
}
