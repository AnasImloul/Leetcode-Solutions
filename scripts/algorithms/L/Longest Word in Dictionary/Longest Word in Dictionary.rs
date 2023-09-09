// Runtime: 6 ms (Top 66.6%) | Memory: 2.18 MB (Top 100.0%)

impl Solution {
    pub fn longest_word(words: Vec<String>) -> String {
        let mut m = std::collections::HashMap::new();
        for w in words {
            m.entry(w.len()).or_insert(Vec::new()).push(w);
        }
        let mut cur = 2_usize;
        let mut level = Vec::new();
        if let Some(v) = m.get(&1) {
            level = v.clone();
        } else {
            return String::new()
        }
        loop {
            let mut new_level = Vec::new();
            if let Some(v) = m.get(&cur) {
                for word in v {
                    if level.iter().any(|w| word.starts_with(w)) {
                        new_level.push(word.clone());
                    }
                }
            } 
            if new_level.is_empty() {
                return level.iter().min().unwrap().to_string()
            }
            level = new_level;
            cur += 1;
        }
    }
}