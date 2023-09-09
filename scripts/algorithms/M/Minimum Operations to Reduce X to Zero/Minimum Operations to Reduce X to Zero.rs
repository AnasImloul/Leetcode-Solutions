// Runtime: 13 ms (Top 100.0%) | Memory: 3.02 MB (Top 66.6%)

use std::cmp::max;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
        let sum: i32 = nums.iter().sum();
        let mut l = 0;
        let mut csum = 0;
        let mut maxlen: i32 = -1;
        for r in 0..nums.len() {
            csum += nums[r];
            while l <= r && csum > sum-x {
                csum -= nums[l];
                l += 1;
            }
            if csum == sum - x {
                maxlen = max(maxlen, (r - l + 1) as i32);
            }
        }
        if maxlen == -1 {-1} else {nums.len() as i32 - maxlen}
    }
}