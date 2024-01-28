// Runtime: 0 ms (Top 100.0%) | Memory: 2.00 MB (Top 68.0%)

impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        let mut n = 1;
        while n < num {
            n = (n << 1) + 1;
        }
        n - num
    }
}
