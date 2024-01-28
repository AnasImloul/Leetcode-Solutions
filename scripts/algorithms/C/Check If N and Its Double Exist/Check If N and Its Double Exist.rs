// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 56.82%)

use std::collections::HashSet;

impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        let mut prev = HashSet::new();
        for n in arr {
            let double = n * 2;
            if prev.contains(&double) {
                return true;
            }
            if n & 1 == 0 {
                let half = n / 2;
                if prev.contains(&half) {
                    return true;
                }
            }
            prev.insert(n);
        }
        false
    }
}
