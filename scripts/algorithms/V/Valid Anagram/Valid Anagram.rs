// Runtime: 1 ms (Top 86.07%) | Memory: 2.30 MB (Top 35.27%)

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
       let mut map = std::collections::HashMap::new();
       s.chars().for_each(|c| *map.entry(c).or_insert(0) += 1); 
       t.chars().for_each(|c| *map.entry(c).or_insert(0) -= 1); 
       !map.into_values().any(|count| count != 0)
    }
}
