// Runtime: 1 ms (Top 82.5%) | Memory: 2.40 MB (Top 32.5%)

impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let mut s_chars: Vec<char> = s.chars().collect();
        let mut t_chars: Vec<char> = t.chars().collect();
        
        let k = Self::process_string(&mut s_chars);
        let p = Self::process_string(&mut t_chars);

        if k != p {
            return false;
        }

        for i in 0..k {
            if s_chars[i] != t_chars[i] {
                return false;
            }
        }

        true
    }

    fn process_string(chars: &mut Vec<char>) -> usize {
        let chars_copy = chars.clone();
        let mut k = 0;
        for &c in chars_copy.iter() {
            if c != '#' {
                chars[k] = c;
                k += 1;
            } else if k > 0 {
                k -= 1;
            }
        }
        k
    }
}
