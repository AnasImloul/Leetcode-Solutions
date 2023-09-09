// Runtime: 10 ms (Top 100.0%) | Memory: 3.13 MB (Top 100.0%)

impl Solution {
    pub fn min_number_operations(target: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut prev = 0;
        for &x in target.iter() {
            if x > prev {
                ans += x - prev;
            }
            prev = x;
        }
        ans
    }
}