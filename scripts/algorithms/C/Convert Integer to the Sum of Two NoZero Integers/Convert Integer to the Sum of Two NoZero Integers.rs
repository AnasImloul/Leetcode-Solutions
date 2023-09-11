// Runtime: 1 ms (Top 40.0%) | Memory: 2.08 MB (Top 60.0%)

impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        let test_zero_in = |mut x: i32| -> bool {
            while x > 0 {
                match x % 10 {
                    0 => return true,
                    _ => x /= 10,
                };
            }
            false
        };

        let mut a = 1;
        while test_zero_in(a) || test_zero_in(n - a) {
            a += 1;
        }
        vec![a, n - a]
    }
}