// Runtime: 13 ms (Top 33.33%) | Memory: 3.80 MB (Top 33.33%)

impl Solution {
    pub fn sum_of_beauties(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut l_max = vec![i32::MIN; n];
        let mut r_min = vec![i32::MAX; n];
        let mut res = 0;

        l_max[0] = nums[0];
        r_min[n - 1] = nums[n - 1];

        for i in 1..n {
            l_max[i] = l_max[i - 1].max(nums[i - 1]);
        }
        for i in (0..n - 1).rev() {
            r_min[i] = r_min[i + 1].min(nums[i + 1]);
        }

        for i in 1..n - 1 {
            if l_max[i] < nums[i] && nums[i] < r_min[i] {
                res += 2;
            } else if nums[i - 1] < nums[i] && nums[i] < nums[i + 1] {
                res += 1;
            }
        }

        res
    }
}
