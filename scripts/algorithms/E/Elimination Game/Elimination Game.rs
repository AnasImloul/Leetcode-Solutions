// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 66.67%)

impl Solution {
    pub fn last_remaining(n: i32) -> i32 {
        let mut n = n;
        let mut head = 1;
        let mut step = 1;
        let mut left = true;
        while n > 1 {
            if left || n % 2 == 1 {
                head += step;
            }
            n /= 2;
            step *= 2;
            left = !left;
        }
        head
    }
}
