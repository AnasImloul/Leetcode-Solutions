// Runtime: 36 ms (Top 100.0%) | Memory: 4.35 MB (Top 100.0%)

use std::collections::BinaryHeap;
use std::cmp::Reverse;
impl Solution {
    pub fn k_sum(mut nums: Vec<i32>, mut k: i32) -> i64 {
        let mut sum = nums.iter().filter(|&&v| v > 0).map(|&v| v as i64).sum::<i64>();
        let mut nums: Vec<_> = nums.into_iter().map(|v| v.abs()).collect();
        nums.sort_unstable();
        
        let mut curr = 0;
        let mut min_heap = BinaryHeap::new();
        min_heap.push(Reverse((nums[0] as i64, 0)));
        k -= 1;
        while !min_heap.is_empty() && k > 0 {
            let Reverse((val, idx)) = min_heap.pop().unwrap();
            curr = val;
            if idx + 1 < nums.len() {
                min_heap.push(Reverse((val + nums[idx + 1] as i64, idx + 1)));
                min_heap.push(Reverse((val - nums[idx] as i64 + nums[idx + 1] as i64, idx + 1)));
            }
            k -= 1;
        }
        sum - curr
    }
}