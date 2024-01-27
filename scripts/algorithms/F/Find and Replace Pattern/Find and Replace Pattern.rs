// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 37.5%)

use std::collections::HashMap;
impl Solution {
    pub fn find_and_replace_pattern(words: Vec<String>, pattern: String) -> Vec<String> {
        let mut ret = vec![];
        
        for word in words {
            if Self::check(&word.chars().collect::<Vec<char>>()[0..], &pattern.chars().collect::<Vec<char>>()[0..]) {
                ret.push(word.clone()); 
            }
        } 
        
        ret
    }
    
    fn check(s: &[char], t: &[char]) -> bool {
        let mut mp1: HashMap<char, char> = HashMap::new();
        let mut mp2: HashMap<char, char> = HashMap::new();
        for i in 0..s.len() {
            let flag1 = if mp1.contains_key(&s[i]) { 1 } else { 0 };
            let flag2 = if mp2.contains_key(&t[i]) { 1 } else { 0 };
            if flag1 + flag2 == 1 { return false }
            if flag1 + flag2 == 2 {
                let (mut c1, mut c2) = (' ', ' '); 
                if let Some(c) = mp1.get(&s[i]) { c1 = *c; }
                if let Some(c) = mp2.get(&t[i]) { c2 = *c; }
                if c1 != t[i] || c2 != s[i] { return false }
                continue;
            }
            mp1.insert(s[i], t[i]);
            mp2.insert(t[i], s[i]);
        }
        true   
    }
}
