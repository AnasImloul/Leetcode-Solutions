// Runtime: 3 ms (Top 90.0%) | Memory: 2.14 MB (Top 20.0%)

use std::cmp;

impl Solution {
    pub fn max_sum_after_partitioning(arr: Vec<i32>, k: i32) -> i32 {
        let mut k = k as usize;
        let n: usize = arr.len();
        let mut dp: Vec<i32> = vec![0; n + 1];
        dp[1] = arr[0];
        for i in 2..n+1 as usize {
            let mut max_so_far: i32 = arr[i - 1];
            for j in 1..k+1 as usize {
                if i < j {
                    break;
                }
                max_so_far = cmp::max(max_so_far, arr[i - j]);
                dp[i] = cmp::max(dp[i], dp[i - j] + (j as i32) * max_so_far);
            }
        }
        dp[n]
    }
}