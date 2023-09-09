// Runtime: 1 ms (Top 100.0%) | Memory: 2.10 MB (Top 50.0%)

impl Solution {
    pub fn max_diff(num: i32) -> i32 {
        let mut a = vec![];
        let mut num = num;
        while num > 9 {
            a.push(num % 10);
            num /= 10;
        }
        a.push(num);
        a.reverse();

        let mut b = a.clone();
        let mut x = -1;
        let mut y = (-1, 0);
        for i in 0..a.len() {
            if x != -1 {
                if a[i] == x {
                    a[i] = 9;
                }
            } else {
                if a[i] != 9 {
                    x = a[i];
                    a[i] = 9;
                }
            }
        }

        if b[0] != 1 {
            y.0 = b[0];
            y.1 = 1;
            b[0] = 1;
        }
        for i in 1..b.len() {
            if y.0 != -1 {
                if b[i] == y.0 {
                    b[i] = y.1;
                }
            } else {
                if b[i] > 1 {
                    y.0 = b[i];
                    b[i] = 0;
                }
            }
        }
        let mut result = 0;
        for i in 0..a.len()-1 {
            result += a[i] - b[i];
            result *= 10;     
        }

        result + a.last().unwrap() - b.last().unwrap()
    }
}