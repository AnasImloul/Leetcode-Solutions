// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 23.08%)

impl Solution {
    pub fn find_integers(n: i32) -> i32 {
        if n == 0 {
            return 1;
        }
        if n == 1 {
            return 2;
        }

        let mut num = n;
        let mut digit = 0_usize;
        while num >= 1 << digit {
            digit += 1;
        }
        let mut digits_of_num = vec![0; digit];
        let mut zero = vec![0; digit];
        let mut one = vec![0; digit];

        zero[0] = 0;
        zero[1] = 1;
        one[0] = 1;
        one[1] = 0;

        let mut sum = 1;

        for i in 0..digit {
            if i > 1 {
                zero[i] = zero[i - 1] + zero[i - 2];
                one[i] = one[i - 1] + one[i - 2];
            }
            if i < digit - 1 {
                sum += zero[i] + one[i];
            }
            digits_of_num[digit - 1 - i] = num % 2;
            num >>= 1;
        }

        let mut i = 0;
        let mut is_valid = true;

        while i + 1 < digit {
            if is_valid {
                if digits_of_num[i] != digits_of_num[i + 1] {
                    zero[i + 1] = zero[i] + one[i];
                    one[i + 1] = zero[i];
                    i += 1;
                } else if digits_of_num[i] == 1 {
                    is_valid = false;
                } else {
                    zero[i + 1] = zero[i] + one[i];
                    one[i + 1] = zero[i] - 1;
                    i += 1;
                }
            } else {
                zero[i + 1] = zero[i] + one[i];
                one[i + 1] = zero[i];
                i += 1;
            }
        }

        sum + zero[digit - 1] + one[digit - 1]
    }
}
