// Runtime: 3 ms (Top 94.74%) | Memory: 2.20 MB (Top 52.63%)

// Rust
use std::collections::HashMap;

impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        let mut mp = HashMap::<i32, Vec<i32>>::new();

        for a in nums {
            let (mut t, mut d) = (a, 1);
            while t > 0 {
                d = d.max(t % 10);
                t /= 10;
            }
            mp.entry(d).or_insert(vec![]).push(a);
        }
        
        let mut ret = -1;
        for (_, mut v) in mp {
            if v.len() < 2 { continue }
            v.sort();
            v.reverse();
            ret = ret.max(v[0] + v[1]);
        }

        ret
    }
}
