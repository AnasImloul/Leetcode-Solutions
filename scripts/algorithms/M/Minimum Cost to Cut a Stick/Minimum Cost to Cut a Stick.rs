// Runtime: 4 ms (Top 83.33%) | Memory: 2.20 MB (Top 100.0%)

impl Solution {
    pub fn min_cost(n: i32, cuts: Vec<i32>) -> i32 {
        let mut a = Vec::with_capacity(cuts.len() + 2);
        a.push(0);
        a.push(n);
        a.extend(cuts);
        a.sort_unstable();

        let mut dp = vec![vec![0; a.len()]; a.len()];

        for len in 2..a.len() {
            for i in 0..a.len() - len {
                let j = i + len;

                let mut t = i32::MAX;
                for k in i + 1..j {
                    t = t.min(dp[i][k] + dp[k][j]);
                }
                dp[i][j] = t + a[j] - a[i];
            }
        }

        dp[0][a.len() - 1]
    }
}
