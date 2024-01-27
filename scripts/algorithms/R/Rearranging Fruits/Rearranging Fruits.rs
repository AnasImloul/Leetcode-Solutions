// Runtime: 41 ms (Top 100.0%) | Memory: 4.70 MB (Top 100.0%)

use std::collections::BTreeMap;

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        let mn = i32::min(*basket1.iter().min().unwrap(), *basket2.iter().min().unwrap()) as i64;
        let (mut mp1, mut mp2) = (BTreeMap::<i32, i32>::new(), BTreeMap::<i32, i32>::new());

        for a in basket1 { *mp1.entry(a).or_insert(0) += 1; }
        for a in basket2 {
            if mp1.contains_key(&a) == false {
                *mp2.entry(a).or_insert(0) += 1;
                continue
            }
            if *mp1.get(&a).unwrap() == 1 { mp1.remove(&a); }
            else                          { *mp1.entry(a).or_insert(0) -= 1; }
        }

        let mut ret = 0;
        while mp1.is_empty() == false {
            let (a, b) = (*mp1.keys().next().unwrap(), *mp2.keys().next().unwrap());
            let (c, d) = (*mp1.keys().next_back().unwrap(), *mp2.keys().next_back().unwrap());
            if a < b {
                let k = i32::min(*mp1.get(&a).unwrap() / 2, *mp2.get(&d).unwrap() / 2);
                if k == 0 { return -1 }
            
                if *mp1.get(&a).unwrap() == 2 * k { mp1.remove(&a); }
                else                              { *mp1.entry(a).or_insert(0) -= 2 * k; }

                if *mp2.get(&d).unwrap() == 2 * k { mp2.remove(&d); }
                else                              { *mp2.entry(d).or_insert(0) -= 2 * k; }

                ret += i64::min((a as i64) * k as i64, mn * 2 * k as i64);
            }  else {
                let k = i32::min(*mp2.get(&b).unwrap() / 2, *mp1.get(&c).unwrap() / 2);
                if k == 0 { return -1 }

                if *mp2.get(&b).unwrap() == 2 * k { mp2.remove(&b); }
                else                              { *mp2.entry(b).or_insert(0) -= 2 * k; }

                if *mp1.get(&c).unwrap() == 2 * k { mp1.remove(&c); }
                else            { *mp1.entry(c).or_insert(0) -= 2 * k; }

                ret += i64::min((b as i64) * k as i64, mn * 2 * k as i64);
            }
        }

        ret
    }
}
