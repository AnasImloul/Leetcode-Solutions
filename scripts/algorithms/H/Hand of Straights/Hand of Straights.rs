// Runtime: 10 ms (Top 100.0%) | Memory: 2.20 MB (Top 92.31%)

impl Solution {
    pub fn is_n_straight_hand(mut hand: Vec<i32>, group_size: i32) -> bool {
        use std::collections::HashMap;
        hand.sort();
        let mut freq = hand.iter().copied().fold(HashMap::new(), |mut acc, x| {
            *acc.entry(x).or_insert(0) += 1;
            acc
        });
        for h in hand {
            if *freq.get(&h).unwrap() == 0 {
                continue;
            }
            for i in 0..group_size {
                if freq.contains_key(&(h + i)) && *freq.get(&(h + i)).unwrap() > 0 {
                    *freq.get_mut(&(h + i)).unwrap() -= 1;
                } else {
                    return false;
                }
            }
        }
        true      
    }
}
