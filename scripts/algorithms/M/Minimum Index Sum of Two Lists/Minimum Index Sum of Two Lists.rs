// Runtime: 10 ms (Top 81.82%) | Memory: 2.40 MB (Top 27.27%)

impl Solution {
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        use std::cmp::Ordering;
        use std::collections::HashMap;

        let map = list1.iter().zip(0..).collect::<HashMap<_, usize>>();
        let mut res = vec![];
        let mut min_sum = usize::MAX;

        for (i2, s2) in list2.into_iter().enumerate() {
            if let Some(&i1) = map.get(&s2) {
                let new_sum = i1 + i2;
                match new_sum.cmp(&min_sum) {
                    Ordering::Less => {
                        min_sum = new_sum;
                        res = vec![s2];
                    }
                    Ordering::Equal => res.push(s2),
                    _ => (),
                }
            }
            if i2 > min_sum {
                break;
            }
        }
        res
    }
}
