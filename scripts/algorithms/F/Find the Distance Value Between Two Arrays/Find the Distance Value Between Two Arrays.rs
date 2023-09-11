// Runtime: 3 ms (Top 35.7%) | Memory: 2.11 MB (Top 42.8%)

impl Solution {
    pub fn find_the_distance_value(arr1: Vec<i32>, mut arr2: Vec<i32>, d: i32) -> i32 {
        arr2.sort_unstable();
        arr1.iter().fold(0, |res, &x| {
            res + (arr2.iter().all(|&y| (x - y).abs() > d) as i32)
        })
    }
}