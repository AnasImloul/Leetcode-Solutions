// Runtime: 8 ms (Top 66.67%) | Memory: 3.60 MB (Top 50.0%)

impl Solution {
    pub fn ways_to_split_array(nums: Vec<i32>) -> i32 {
        let tot: i64 = nums.iter().map(|&v| v as i64).sum();
        let mut cum = 0;
        let mut ans = 0;
        let n = nums.len();
        for i in 0..n-1 {
            let v = nums[i] as i64;
            cum += v;
            let tail = tot - cum;
            // println!("cum {cum}, tot - cum {tail}");
            if cum >= tail {
                ans += 1;
            }
        }
        ans
    }
}
