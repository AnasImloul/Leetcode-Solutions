// Runtime: 87 ms (Top 20.0%) | Memory: 16.95 MB (Top 100.0%)

use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn restore_array(adjacent_pairs: Vec<Vec<i32>>) -> Vec<i32> {
        let mut mp = HashMap::<i32, Vec<i32>>::new();
        
        for p in adjacent_pairs {
            mp.entry(p[0]).or_insert(vec![]).push(p[1]);
            mp.entry(p[1]).or_insert(vec![]).push(p[0]);
        } 
        
        let mut start = 0;
        for (k, v) in &mp {
            if v.len() == 2 { continue }
            start = *k;
            break
        }
        
        let mut s = HashSet::new();
        let mut ret = vec![start];
        s.insert(start);
        
        while mp.contains_key(&start) {
            let mut v = mp.get(&start).unwrap();
            let mut done = true;
            for u in mp.get(&start).unwrap() {
                if s.contains(&u) { continue }
                start = *u;
                ret.push(*u);
                s.insert(*u);
                done = false;
                break
            }
            if done { break }
        }
        
        ret
    }
}