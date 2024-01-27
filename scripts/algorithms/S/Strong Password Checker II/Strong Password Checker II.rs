// Runtime: 1 ms (Top 100.0%) | Memory: 2.10 MB (Top 100.0%)

impl Solution {
    pub fn strong_password_checker_ii(password: String) -> bool {
        if password.len() < 8 {
            return false;
        }

        let mut res = 0;
        let mut prev_char = ' ';
        for c in password.chars() {
            match c == prev_char {
                true => return false,
                _ if c.is_ascii_lowercase() => res |= 0b1,
                _ if c.is_ascii_uppercase() => res |= 0b10,
                _ if c.is_ascii_digit() => res |= 0b100,
                _ => res |= 0b1000, // "!@#$%^&*()-+"
            }
            prev_char = c;
        }
        res == 0b1111
    }
}
