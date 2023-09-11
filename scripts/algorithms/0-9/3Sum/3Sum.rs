// Runtime: 45 ms (Top 60.5%) | Memory: 4.16 MB (Top 41.5%)

use std::collections::HashSet;

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut in_order_nums = nums.clone();
        in_order_nums.sort();
        let m = &in_order_nums[..];

        let mut res: HashSet<Vec<i32>> = HashSet::new();
        for i in 0..in_order_nums.len() - 2 {
            let n1 = m[i];
            let mut j = i + 1;
            let mut k = in_order_nums.len() - 1;

            while j < k {
                let n2 = m[j];
                let n3 = m[k];
                let sum = n1 + n2 + n3;
                if sum < 0 {
                    j += 1;
                } else if sum > 0 {
                    k -= 1;
                } else {
                    res.insert(vec![n1, n2, n3]);
                    while j < k && m[j] == n2 {
                        j += 1;
                    }
                    while j < k && m[k] == n3 {
                        k -= 1;
                    }
                }
            }
        }

        res.into_iter().collect::<Vec<Vec<i32>>>()
    }
}