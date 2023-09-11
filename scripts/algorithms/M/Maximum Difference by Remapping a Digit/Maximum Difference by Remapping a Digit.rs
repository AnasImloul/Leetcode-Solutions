// Runtime: 0 ms (Top 100.0%) | Memory: 2.62 MB (Top 42.8%)

impl Solution {
    pub fn min_max_difference(mut num: i32) -> i32 {
        let (mut max_val, mut min_val) = (0, 0);
        let (mut max_dig_rm, mut min_dig_rm) = (-1, -1);
        let p = (num as f64).log10() as u32;
        let mut div = 10_i32.pow(p);

        for _ in 0..=p {
            let digit = num / div;
            max_val *= 10;
            min_val *= 10;

            max_val += match (max_dig_rm, digit) {
                (-1, x) => {
                    if x != 9 {
                        max_dig_rm = x
                    }
                    9
                }
                (x, y) if x == y => 9,
                _ => digit,
            };

            min_val += match (min_dig_rm, digit) {
                (-1, x) => {
                    if x != 0 {
                        min_dig_rm = x
                    }
                    0
                }
                (x, y) if x == y => 0,
                _ => digit,
            };

            num %= div;
            div /= 10;
        }

        max_val - min_val
    }
}
