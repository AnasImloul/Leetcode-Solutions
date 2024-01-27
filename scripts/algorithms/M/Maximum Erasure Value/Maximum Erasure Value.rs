// Runtime: 14 ms (Top 100.0%) | Memory: 3.10 MB (Top 62.5%)

/// @author: Leon
/// https://leetcode.com/problems/maximum-erasure-value/
/// Time Complexity:    O(`len_n`)
/// Space Complexity:   O(`RANGE`)
impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        const RANGE: usize = 10e4 as usize + 7;
        let len_n: usize = nums.len();
        let mut freqs: Vec<u16> = vec![0; RANGE];
        let mut lo: usize = 0;
        let mut most: i32 = 0;
        let mut sum: i32 = 0;
        for hi in 0..len_n {
            sum += nums[hi];
            freqs[nums[hi] as usize] += 1;
            while lo < hi && freqs[nums[hi] as usize] > 1 {
                sum -= nums[lo];
                freqs[nums[lo] as usize] -= 1;
                lo += 1;
            }
            most = std::cmp::max(most, sum);
        }
        most
    }
}
