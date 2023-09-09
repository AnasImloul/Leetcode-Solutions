// Runtime: 16 ms (Top 50.0%) | Memory: 2.14 MB (Top 100.0%)

const MODULO: usize = 1000000007;

impl Solution {
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
        let (n, k, target) = (n as usize, k as usize, target as usize);
        let (mut dp_prev, mut dp_curr) = (vec![0; target + 1], vec![0; target + 1]);
        dp_prev[0] = 1;
        for _ in 0..n {
            for j in 1..=target {
                for m in 1..=k {
                    if m <= j {
                        dp_curr[j] = (dp_curr[j] + dp_prev[j - m]) % MODULO;
                    }
                }
            }
            std::mem::swap(&mut dp_curr, &mut dp_prev);
            dp_curr.fill(0);
        }
        dp_prev[target] as _
    }
}