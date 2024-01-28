// Runtime: 3 ms (Top 74.71%) | Memory: 2.20 MB (Top 87.65%)

use std::cmp::Ordering;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut min: i32 = 0;
        let mut max = (nums.len() - 1) as i32; // use i32 to be able to go under zero

        while min <= max {
            let mid = (min + max) / 2;
            match nums[mid as usize].cmp(&target) {
                Ordering::Equal => return mid,
                Ordering::Less => min = mid + 1,
                Ordering::Greater => max = mid - 1,
            }
        }
        return -1;
    }
}
