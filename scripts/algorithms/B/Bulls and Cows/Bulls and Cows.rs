// Runtime: 1 ms (Top 87.5%) | Memory: 2.10 MB (Top 87.5%)

impl Solution {
    pub fn get_hint(secret: String, guess: String) -> String {
        let (mut a, mut b) = (0, 0);
        let mut d1 = [0; 10];
        let mut d2 = [0; 10];
        for (s, g) in secret.as_bytes().iter().zip(guess.as_bytes()) {
            if s == g {
                a += 1;
            } else {
                d1[(s - b'0') as usize] += 1;
                d2[(g - b'0') as usize] += 1;
            }
        }
        for i in 0..10 {
            b += std::cmp::min(d1[i], d2[i]);
        }
        format!("{}A{}B", a, b)
    }
}
