// Runtime: 14 ms (Top 100.0%) | Memory: 2.36 MB (Top 100.0%)

use std::collections::*;
impl Solution {
    pub fn can_reorder_doubled(arr: Vec<i32>) -> bool {
        let mut btreemap = BTreeMap::new();
        let mut count = 0;
        for v in arr {
            if v != 0 {
                count += 1;
                *btreemap.entry(v).or_insert(0) += 1;  
            } 
        }
        if count % 2 == 1 {
            return false
        }

        while btreemap.keys().len() > 0 {
            let (&val, &num) = btreemap.iter().next().unwrap();
            let tval = if val < 0 {
                if val % 2 != 0 {
                    return false
                }
                val / 2
            } else {
                val * 2
            };

            if let Some(num) = btreemap.get_mut(&tval) {
                if *num == 1 {
                    btreemap.remove(&tval);
                } else {
                    *num -= 1;
                }
            } else {
                return false;
            }
            
            if num == 1 {
                btreemap.remove(&val);
            } else {
                btreemap.insert(val, num-1);
            }
        }
        true
    }
}