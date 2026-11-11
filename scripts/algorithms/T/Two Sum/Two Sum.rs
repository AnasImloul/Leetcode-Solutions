// Runtime: 0 ms (Top 100.00%) | Memory: 2.30 MB (Top 58.11%)

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let length = nums.len();

        for gap in 1..length {
            for right in gap..length {
                let left = right - gap;
                if nums[left] + nums[right] == target {
                    return vec![left as i32, right as i32];
                }
            }
        }

        vec![] // Return an empty vector if no solution found
    }
}
