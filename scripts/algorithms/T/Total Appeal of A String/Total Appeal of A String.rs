// Runtime: 0 ms (Top 100.0%) | Memory: 3.40 MB (Top 25.0%)

impl Solution {
    pub fn appeal_sum(s: String) -> i64 {
        let n = s.len();
        let mut f = vec![0; n];
        let mut last_pos = [-1; 26];
        
        // println!("last_pos {:?}", last_pos);
        
        for (i, c) in s.chars().enumerate() {
            let char_id = c as usize - 'a' as usize;
            let i2 = i as i64;
            // println!("char id {}", char_id);
            if i == 0 {
                f[i] = 1;
                last_pos[char_id] = i2;
                continue;
            }
            f[i] += f[i-1] + i2 - last_pos[char_id];
            last_pos[char_id] = i2;
        }
        
        let ans = f.iter().sum();
        
        ans
    }
}
