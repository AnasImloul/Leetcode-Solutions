// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 76.92%)

use std::collections::HashMap;
impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        let mut hm = HashMap::new();
        
        for i in arr{
         *hm.entry(i).or_insert(0) += 1;
        }
        let mut max = -1;
        for (key, value) in hm{
            if key == value && key > max{
                    max = key;
            }
        }
        max
    }
}
