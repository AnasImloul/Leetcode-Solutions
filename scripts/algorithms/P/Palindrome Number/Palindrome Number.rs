// Runtime: 16 ms (Top 11.5%) | Memory: 2.00 MB (Top 60.3%)

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        return x.to_string().chars().rev().eq(x.to_string().chars())
    }
}