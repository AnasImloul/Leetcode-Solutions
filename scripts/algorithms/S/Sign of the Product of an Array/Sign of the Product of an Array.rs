// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 14.71%)

impl Solution {
    pub fn array_sign(nums: Vec<i32>) -> i32 {
        nums.iter().fold(1, |prod, &x| prod * x.signum())
    }
}
