// Runtime: 2 ms (Top 66.84%) | Memory: 2.20 MB (Top 34.71%)

use std::ops::RangeInclusive;

impl Solution {
    /// Finds the longest palindrome within the given string.
    #[must_use]
    pub fn longest_palindrome(s: String) -> String {
        // The problem description assures us that `s` contains only ASCII
        // characters, but in real code, this `assert!()` statement would be
        // necessary. Or, better yet, we'd use the `ascii` crate to make the
        // invalid states unrepresentable.
        // assert!(s.is_ascii());

        // In real Rust code, `s` would already be `&str` and this conversion
        // would be unnecessary.
        let s = s.as_str();

        (0..s.len())
            .fold("", |current_longest, idx| {
                current_longest
                    .longest(s.longest_palindrome_around(idx..=idx))
                    .longest(s.longest_palindrome_around(idx..=idx + 1))
            })
            .into()
    }
}

trait LongestPalindrome {
    type Idx;

    /// The 3rd approach shown in LeetCode's official explanation.
    fn longest_palindrome_around(&self, center: RangeInclusive<Self::Idx>) -> &Self;

    /// A convenience function for chaining comparisons.
    fn longest<'a>(&'a self, other: &'a Self) -> &'a Self;
}

impl LongestPalindrome for str {
    type Idx = usize;

    fn longest_palindrome_around(&self, center: RangeInclusive<Self::Idx>) -> &Self {
        let (mut start, mut end) = center.into_inner();
        let characters = self.as_bytes();

        loop {
            if characters.get(start) != characters.get(end) {
                return &self[start + 1..end];
            }

            if let (Some(new_start), Some(new_end)) = (start.checked_sub(1), end.checked_add(1)) {
                start = new_start;
                end = new_end;
            } else {
                return &self[start..=end];
            }
        }
    }

    fn longest<'a>(&'a self, other: &'a Self) -> &'a Self {
        if self.len() > other.len() {
            self
        } else {
            other
        }
    }
}
