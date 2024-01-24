// Runtime: 0 ms (Top 100.0%) | Memory: 2.00 MB (Top 100.0%)

impl Solution {
    pub fn min_operations(mut n: i32) -> i32 {
        let mut ans = 0;
        let mut temp;

        while n > 0 {
            ans += 1;
            temp = 0;
            while (1 << temp) < n {
                temp += 1;
            }

            n = i32::min(n - (1 << (temp - 1)), (1 << temp) - n);
        }

        ans
    }
}
