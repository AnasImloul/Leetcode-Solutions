// Runtime: 3 ms (Top 100.0%) | Memory: 2.20 MB (Top 20.0%)

use std::collections::HashMap;
impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let right_prefix = {
            let mut right_prefix = nums
                    .iter()
                    .rev()
                    .scan(0, |acc, &el| {
                        let out = *acc | el;
                        *acc = out;
                        Some(out)
                    })
                    .collect::<Vec<i32>>();
            right_prefix.reverse();
            right_prefix
        };

        let mut cache = HashMap::new();
        recursive(&nums, &right_prefix, &mut cache, right_prefix[0])
    }
}

fn recursive(nums: &[i32], right_prefix: &[i32], cache: &mut HashMap<(usize, i32), i32>, target: i32) -> i32 {
    if let Some(ans) = cache.get(&(nums.len(), target)) {
        return *ans;
    }

    if nums.is_empty() {
        if target == 0 {
            return 1;
        } else {
            return 0;
        }
    }
    let n = nums.len();

    if right_prefix[0] & target != target {
        cache.insert((n, target), 0);
        return 0;
    }

    let ways_without = recursive(&nums[1..], &right_prefix[1..], cache, target);
    let needed_with = target ^ (target & nums[0]);
    let ways_with = recursive(&nums[1..], &right_prefix[1..], cache, needed_with);

    cache.insert((n, target), ways_without + ways_with);
    ways_without + ways_with
}
