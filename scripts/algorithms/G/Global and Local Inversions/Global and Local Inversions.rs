// Runtime: 12 ms (Top 100.0%) | Memory: 3.21 MB (Top 50.0%)

impl Solution {
    pub fn is_ideal_permutation(nums: Vec<i32>) -> bool {
        fn _is_ideal_permutation(nums: Vec<i32>) -> Option<bool> {
            let mut max = 0;
            for i in 0..nums.len().checked_sub(2)? {
                max = std::cmp::max(max, *nums.get(i)?);
                if max > *nums.get(i + 2)? {
                    return Some(false);
                }
            }
            Some(true)
        }
        _is_ideal_permutation(nums).unwrap_or(true)
    }
}