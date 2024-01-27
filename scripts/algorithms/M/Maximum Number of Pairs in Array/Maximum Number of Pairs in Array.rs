// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 100.0%)

use std::collections::HashMap;

impl Solution {
    pub fn number_of_pairs(nums: Vec<i32>) -> Vec<i32> {
        let mut mapped_nums = HashMap::new();

        nums.iter().for_each(|&x| {
            mapped_nums
                .entry(x)
                .and_modify(|value| *value += 1)
                .or_insert(1);
        });

        mapped_nums
            .values()
            .map(|&value| (value / 2, value % 2))
            .fold(vec![0, 0], |mut acc, value| {
                acc[0] += value.0;
                acc[1] += value.1;
                acc
            })
    }
}

