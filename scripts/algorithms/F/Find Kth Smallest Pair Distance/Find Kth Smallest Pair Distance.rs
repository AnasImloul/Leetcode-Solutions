// Runtime: 2 ms (Top 100.0%) | Memory: 2.20 MB (Top 75.0%)

impl Solution {
    pub fn smallest_distance_pair(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort_unstable();
        let (n, k) = (nums.len(), k as usize);
        let mut lo = 0;
        let mut hi = nums[n - 1] - nums[0];

        while lo < hi {
            let mid = lo + (hi - lo) / 2;
            let mut count = 0;
            let mut left = 0;

            for right in 0..n {
                while nums[right] - nums[left] > mid {
                    left += 1;
                }
                count += right - left;
            }

            if count < k {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        lo
    }
}
