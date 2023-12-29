// Runtime: 2 ms (Top 20.53%) | Memory: 2.00 MB (Top 53.64%)

impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let mut ans: i64 = 1;
        for i in 1..=m as i64 - 1 {
            ans = ans * (n as i64 - 1 + i) / i;
        }
        ans as i32
    }
}
