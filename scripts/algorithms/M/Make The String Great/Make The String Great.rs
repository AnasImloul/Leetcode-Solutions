// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 81.82%)

impl Solution {
    pub fn make_good(s: String) -> String {
        s.chars().fold(String::new(), |mut rez, c2| {
            match (rez.pop(), c2) {
                (None, c2) => c2.to_string(),
                (Some(c1), c2) 
                    if c1 != c2 && c1.to_lowercase().eq(c2.to_lowercase())
                    => rez,
                (Some(c1), c2) => rez + &c1.to_string() + &c2.to_string(),
            }
        })
    }
}
