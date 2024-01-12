// Runtime: 32 ms (Top 100.0%) | Memory: 3.70 MB (Top 100.0%)

impl Solution {
    pub fn count_fair_pairs(mut nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        nums.sort_unstable();
        let mut ans = 0i64;
        for (idx, num) in nums.iter().copied().enumerate() {
            let l_bound = nums[idx+1..].partition_point(|&n| n+num < lower);
            let u_bound = nums[idx+1..].partition_point(|&n| n+num <= upper);
            ans += (u_bound - l_bound) as i64;
        }
        ans
    }
}
