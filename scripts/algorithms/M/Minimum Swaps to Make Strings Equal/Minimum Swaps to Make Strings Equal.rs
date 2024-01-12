// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 28.57%)

impl Solution {
    pub fn minimum_swap(s1: String, s2: String) -> i32 {
        let mut x1 = 0;
        let mut y1 = 0;
        for (c1, c2) in s1.chars().zip(s2.chars()) {
            if c1 == 'x' && c2 == 'y' {
                x1 += 1;
            } else if c1 == 'y' && c2 == 'x' {
                y1 += 1;
            }
        }
        let mut ans = 0;
        if x1 % 2 == 1 && y1 % 2 == 1 {
            ans += 2;
            x1 -= 1;
            y1 -= 1;
        }
        ans += x1 / 2 + y1 / 2;
        if x1 % 2 == 1 || y1 % 2 == 1 {
            return -1;
        }
        ans
    }
}
