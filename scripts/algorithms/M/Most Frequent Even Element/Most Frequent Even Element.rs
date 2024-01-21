// Runtime: 3 ms (Top 100.0%) | Memory: 2.20 MB (Top 63.64%)

use std::collections::HashMap;
impl Solution {
    pub fn most_frequent_even(nums: Vec<i32>) -> i32 {
        let mut hm:HashMap<i32,i32> = HashMap::new();
        for n in nums.iter(){
            if n % 2 == 0{
                *hm.entry(*n).or_insert(0) += 1;
            }
        }
        let max = hm.iter().map(|f| f.1).max();
        match max {
            Some(m) =>{
                let res = hm.iter().filter(|p| p.1 == m).map(|f| f.0).collect::<Vec<_>>();
                **res.iter().min().unwrap()
            },
            None =>{
                return -1;
            }
        }
    }
}
