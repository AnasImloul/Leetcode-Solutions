// Runtime: 31 ms (Top 50.0%) | Memory: 4.04 MB (Top 50.0%)

const DIVISOR: i32 = 3;

impl Solution {
    pub fn max_kelements(nums: Vec<i32>, k: i32) -> i64 {
        let mut heap = std::collections::BinaryHeap::from(nums);
        (0..k).fold(0, |res, _| {
            let value = heap.pop().unwrap();
            heap.push((value + DIVISOR - 1) / DIVISOR);
            res + value as i64
        })
    }
}