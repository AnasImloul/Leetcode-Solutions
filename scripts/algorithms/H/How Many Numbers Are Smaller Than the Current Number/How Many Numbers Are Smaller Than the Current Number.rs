// Runtime: 2 ms (Top 90.91%) | Memory: 2.10 MB (Top 84.09%)

impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        nums.iter()
            .map(|i| nums.iter().filter(|j| *j < &i).count() as i32)
            .collect()
    }
}
