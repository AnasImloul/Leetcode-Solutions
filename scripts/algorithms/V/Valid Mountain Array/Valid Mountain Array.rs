// Runtime: 3 ms (Top 60.3%) | Memory: 2.15 MB (Top 67.9%)

impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        (1..arr.len())
            .find(|&i| arr[i - 1] >= arr[i])
            .map_or(false, |j| j > 1 && (j..arr.len()).all(|j| arr[j - 1] > arr[j]))
    }
}