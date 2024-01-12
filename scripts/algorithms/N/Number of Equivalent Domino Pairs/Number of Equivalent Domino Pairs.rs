// Runtime: 6 ms (Top 90.91%) | Memory: 4.50 MB (Top 27.27%)

use std::collections::HashMap;

impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut count = HashMap::new();
        for d in dominoes {
            let d = (d[0].min(d[1]), d[0].max(d[1]));
            *count.entry(d).or_insert(0) += 1;
        }
        count.values().map(|c| (c * (c - 1)) / 2).sum()
    }
}
