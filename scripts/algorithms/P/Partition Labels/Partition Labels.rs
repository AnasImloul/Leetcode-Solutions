// Runtime: 3 ms (Top 5.5%) | Memory: 2.08 MB (Top 66.6%)

use std::collections::HashMap;
use std::cmp::max;
impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let mut h1:HashMap<String,i32> = HashMap::new();
        for (i,s) in s.chars().enumerate(){
            h1.insert(s.to_string(),i as i32);
        }

        let mut v1:Vec<i32> = Vec::new();
        let mut res:i32 = 0;
        let mut out = 0;
        for (i,s) in s.chars().enumerate(){
            res = max(h1[&s.to_string()],res);
            if (i as i32) == res{
                v1.push(res+1 - out);
                out = res+1;
            }
        }
        return v1

    }
}