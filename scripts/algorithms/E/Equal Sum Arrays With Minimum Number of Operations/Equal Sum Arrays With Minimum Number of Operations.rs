// Runtime: 30 ms (Top 33.33%) | Memory: 4.20 MB (Top 33.33%)

use std::collections::BinaryHeap;

impl Solution {
    pub fn min_operations(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let a: i32 = nums1.iter().map(|&x| x as i32).sum();
        let b = nums2.iter().map(|&x| x as i32).sum();
        if (a < b) { return Self::min_operations(nums2, nums1); }
        
        let mut pq = BinaryHeap::new();
        let mut amt = a - b;
        
        for n in nums1 {
            if n > 1 { pq.push(n - 1); }
        }
        
        for n in nums2 {
            if n < 6 { pq.push(6 - n); }
        }
        
        let mut ret = 0;
        while amt > 0 && pq.is_empty() == false {
            amt -= pq.pop().unwrap();
            ret += 1;
        }
        
        if amt > 0 { return -1 }
        ret
    }
}
