// Runtime: 23 ms (Top 100.0%) | Memory: 4.80 MB (Top 66.67%)

use std::collections::HashMap;

impl Solution {
    pub fn is_possible_divide(mut nums: Vec<i32>, k: i32) -> bool {
        if nums.len() % k as usize != 0 { return false; }

        nums.sort_unstable();

        let mut freq: HashMap<i32, i32> = HashMap::new();
        nums.iter().for_each(|&num| {
            *freq.entry(num).or_insert(0) += 1;
        });

        for num in nums {
            if freq[&num] != 0 {
                let occ = freq[&num];
                for i in num..num + k {
                    match freq.get_mut(&i) {
                        Some(cnt) => if *cnt < 0 { return false; } else { *cnt -= occ; },
                        None => return false
                    }
                }
            }
        }
        true
    }
}
