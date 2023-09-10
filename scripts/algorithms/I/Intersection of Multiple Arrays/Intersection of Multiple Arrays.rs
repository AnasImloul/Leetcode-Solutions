// Runtime: 3 ms (Top 33.3%) | Memory: 2.49 MB (Top 50.0%)

use std::collections::HashMap;

impl Solution {
   pub fn intersection(nums : Vec<Vec<i32>>) -> Vec<i32> {
        let mut map = HashMap::new();
        let mut res = vec![];
        for i in 0..nums.len() {
            for j in 0..nums[i].len() {
                *map.entry(nums[i][j]).or_insert(0) +=1;
            }
        }
        for (key,value) in &map {
            if *value == nums.len() {
                res.push(*key);
            }
        }
        res.sort();
        res
    }
}