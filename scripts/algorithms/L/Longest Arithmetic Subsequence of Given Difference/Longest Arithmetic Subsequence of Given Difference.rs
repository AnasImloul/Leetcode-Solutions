// Runtime: 3 ms (Top 100.0%) | Memory: 3.00 MB (Top 86.96%)

const RANGE_MIN: i32 = -10_000;
const RANGE_MAX: i32 = 10_000;

impl Solution {
    pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
        let range = (RANGE_MAX - RANGE_MIN + 1) as usize;
        fn offset(i: i32) -> Option<usize> {
            if RANGE_MIN <= i && i <= RANGE_MAX {
                Some((i - RANGE_MIN) as usize)
            } else {
                None
            }
        }
        /// "Length when last seen"; longest subseq when we last saw that arr[i] value
        let mut lwls = vec![0_i32; range];
        let mut best = 1;
        for &a in arr.iter().rev() {
            let old = offset(a + difference).map(|i| lwls[i]).unwrap_or(0);
            let new_idx = offset(a).unwrap();  // safety: problem constraints
            let len = lwls[new_idx].max(old + 1);
            lwls[new_idx] = len;
            best = best.max(len);
        }
        best
    }
}
