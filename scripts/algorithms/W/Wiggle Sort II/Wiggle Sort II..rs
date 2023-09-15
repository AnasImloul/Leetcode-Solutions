// Runtime: 6 ms (Top 63.6%) | Memory: 2.39 MB (Top 81.8%)

use std::cmp::Ordering::{Less, Equal, Greater};

impl Solution {
    pub fn wiggle_sort(nums: &mut Vec<i32>) {
        if Self::wiggle_forward(&mut nums[..]) {
            return;
        }
        if Self::wiggle_backward(&mut nums[..]) {
            return;
        }
        let pivot = nums[0];
        if Self::wiggle_pivot(&mut nums[..], pivot) {
            return;
        }
        panic!("not wiggle-sortable");
    }
    fn wiggle_forward(nums: &mut [i32]) -> bool {
        let mut i = 0;
        let mut j = 0;
        while j < nums.len() {
            // INVARIANTS:
            // (0) 0 <= i <= j <= nums.len, i < nums.len
            // (1) nums[..i+1] is wiggle-sorted
            // (2) nums[i..j] are all identical
            // (3) nums[j..] are unchanged since the start of the loop
            if j <= i {
                j = i + 1;
                continue;
            }
            match (i % 2 == 0, i32::cmp(&nums[j], &nums[i])) {
                (true, Greater) | (false, Less) => {
                    if j <= i + 1 {
                        i += 1;
                    } else {
                        nums.swap(j, i + 1);
                        i += 2;
                        j += 1;
                    }
                },
                (true, Less) | (false, Greater) => {
                    nums.swap(j, i);
                    i += 1;
                    j += 1;
                },
                (_, Equal) => j += 1,
            }
        }
        return i >= nums.len() - 1;
    }
    fn wiggle_backward(nums: &mut [i32]) -> bool {
        let mut i = nums.len();
        let mut j = nums.len();
        while j > 0 {
            // INVARIANTS HERE:
            // (0) 0 <= j <= i <= nums.len and 0 < i
            // (1) nums[i-1..] is wiggle-sorted
            // (2) nums[j..i] are all identical
            // (3) nums[..j] are unchanged since the start of the loop
            if j >= i {
                j = i - 1;
                continue;
            }
            match (i % 2 == 0, i32::cmp(&nums[j-1], &nums[i-1])) {
                (true, Less) | (false, Greater) => {
                    if j >= i - 1 {
                        i -= 1;
                    } else {
                        nums.swap(j - 1, i - 2);
                        i -= 2;
                        j -= 1;
                    }
                },
                (true, Greater) | (false, Less) => {
                    nums.swap(j - 1, i - 1);
                    i -= 1;
                    j -= 1;
                },
                (_, Equal) => j -= 1,
            }
        }
        return i <= 1;
    }
    fn wiggle_pivot(nums: &mut [i32], pivot: i32) -> bool {
        let n = nums.len();
        let m = (n + 1) / 2;
        let index = move |i: usize| if i < m {
            2 * (m - i - 1)
        } else {
            2 * (n - i) - 1
        };
        let mut min_i = 0;
        let mut max_i = n;
        let mut i = 0;
        while i < max_i {
            match nums[index(i)].cmp(&pivot) {
                Less => {
                    nums.swap(index(i), index(min_i));
                    i += 1;
                    min_i += 1;
                },
                Equal => {
                    i += 1;
                },
                Greater => {
                    nums.swap(index(i), index(max_i - 1));
                    max_i -= 1;
                },
            }
        }
        return min_i <= m && max_i >= m;
    }
}