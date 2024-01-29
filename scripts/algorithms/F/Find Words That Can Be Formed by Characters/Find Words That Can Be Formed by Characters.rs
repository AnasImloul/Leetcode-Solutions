// Runtime: 3 ms (Top 87.04%) | Memory: 2.40 MB (Top 32.67%)

impl Solution {
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        let mut bank = [0; 26];
        for i in chars.as_bytes() {
            bank[*i as usize - 'a' as usize] += 1;
        }
        let bank = bank;    // make immutable
        let mut ans = 0;
        'out: for w in words.iter() {
            let mut bank = bank;
            for i in w.as_bytes() {
                let idx = *i as usize - 'a' as usize;
                bank[idx] -= 1;
                if bank[idx] < 0 {
                    continue 'out;
                }
            }
            ans += w.len();
        }
        ans as i32
    }
}
