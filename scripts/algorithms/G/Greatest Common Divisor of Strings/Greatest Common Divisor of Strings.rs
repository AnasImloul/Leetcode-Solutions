// Runtime: 1 ms (Top 86.0%) | Memory: 2.00 MB (Top 89.5%)

impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        if &(str1.clone() + &str2) != &(str2.clone() + &str1) {
            return "".to_string();
        }
        let length = gcd(str1.len(), str2.len());
        str1[0..length].to_owned()
    }
}
pub fn gcd(n1: usize, n2: usize) -> usize{
    if n2 == 0 {
        return n1;
    }
    gcd(n2, n1 % n2)
}
