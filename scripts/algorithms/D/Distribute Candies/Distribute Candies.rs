// Runtime: 22 ms (Top 100.0%) | Memory: 2.38 MB (Top 35.2%)

use std::collections::HashSet;

impl Solution {
    pub fn distribute_candies(candy_type: Vec<i32>) -> i32 {
        let len = candy_type.len();
        let hashset: HashSet<i32> = candy_type.into_iter().collect();
        std::cmp::min(len / 2, hashset.len()) as i32
    }
}