// Runtime: 8 ms (Top 100.0%) | Memory: 2.95 MB (Top 100.0%)

/// @author: Leon
/// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
/// Time Complexity:    O(`len_gs`)
/// Space Complexity:   O(1)
impl Solution {
    pub fn maximum_groups(grades: Vec<i32>) -> i32 {
        let len_gs: i32 = grades.len() as i32;
        let mut cnt: i32 = 0;
        // the running length of the (current) subarray
        let mut len: i32 = 1;
        // the accumulated sum of lengths (of subarrays)
        let mut sum: i32 = 0;
        while sum + len <= len_gs {
            cnt += 1;
            sum += len;
            len += 1;
        }
        cnt
    }
}