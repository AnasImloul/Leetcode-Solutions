// Runtime: 13 ms (Top 83.33%) | Memory: 2.30 MB (Top 100.0%)

impl Solution {
    pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        let mut total = 0;
        let mut odd = 0;
        let mut count = 0;

        let mut j = 0;
        let is_odd = |x| x % 2 == 1;

        for &num in nums.iter() {
            if is_odd(num) {
                odd += 1;
                count = 0;
            }

            while odd == k {
                if is_odd(nums[j]) {
                    odd -= 1;
                }
                count += 1;
                j += 1;
            }
            total += count;
        }

        total as i32
    }
}

