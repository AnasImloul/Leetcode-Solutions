// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 22.22%)

impl Solution {
    pub fn check_possibility(nums: Vec<i32>) -> bool {
        nums.windows(2).filter(|w| w[0] > w[1]).count() < 2
            && nums
                .windows(4)
                .all(|w| w[1] <= w[2] || w[0] <= w[2] || w[1] <= w[3])
    }
}
