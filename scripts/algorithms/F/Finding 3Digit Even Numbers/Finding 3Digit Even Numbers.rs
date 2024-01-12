// Runtime: 2 ms (Top 80.0%) | Memory: 2.10 MB (Top 40.0%)

impl Solution {
    pub fn find_even_numbers(mut digits: Vec<i32>) -> Vec<i32> {
        let mut counts = vec![0; 10];
        for i in 0..digits.len() {
            counts[digits[i] as usize] += 1;
        }

        let mut res = Vec::with_capacity(450);
        for n in (100..1000 as usize).step_by(2) {
            let ones = n % 10;
            let tens = n / 10 % 10;
            let hundreds = n / 100;

            counts[ones] -= 1;
            counts[tens] -= 1;
            counts[hundreds] -= 1;

            if counts[ones] >= 0 && counts[tens] >= 0 && counts[hundreds] >= 0 {
                res.push(n as i32);
            }

            counts[ones] += 1;
            counts[tens] += 1;
            counts[hundreds] += 1;
        }

        res
    }
}
