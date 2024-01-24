// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 25.0%)

impl Solution {
    pub fn thousand_separator(n: i32) -> String {
        n.to_string()
            .chars()
            .collect::<Vec<_>>()
            .rchunks(3)
            .rev()
            .map(|v| v.iter().collect::<String>())
            .collect::<Vec<_>>()
            .join(".")
    }
}
