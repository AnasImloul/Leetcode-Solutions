// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 16.67%)

impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        nums
            .into_iter()
            .fold((0, 0, 0), |(prev, sum, max), n| {
                // if n <= prev, sum of previous elements in
                // the subarray is zero
                let sum2 = n + if n > prev { sum } else { 0 };

                (n, sum2, max.max(sum2))
            })
            .2
    }
}
