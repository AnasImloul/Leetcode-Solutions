// Runtime: 23 ms (Top 88.89%) | Memory: 7.00 MB (Top 33.33%)

impl Solution {
    pub fn total_strength(strength: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let strength = strength.into_iter().map(|x| x as i64).collect::<Vec<_>>();
        let N = strength.len();
        let N_i64 = strength.len() as i64;

        let mut ps_l = vec![0; strength.len() + 1];
        let mut pm_l = vec![0; strength.len() + 1];

        for i in 0..N {
            ps_l[i + 1] = (ps_l[i] + strength[i]) % MOD;
            let i_64 = i as i64;
            pm_l[i + 1] = (pm_l[i] + (i_64 + 1) * strength[i]) % MOD;
        }

        let mut ps_r = vec![0; strength.len() + 1];
        let mut pm_r = vec![0; strength.len() + 1];

        for i in (0..N).rev() {
            ps_r[i] = (ps_r[i + 1] + strength[i]) % MOD;
            let i_64 = i as i64;
            pm_r[i] = (pm_r[i + 1] + (N_i64 - i_64) * strength[i]) % MOD;
        }

        let mut stack = vec![];
        let mut ans = 0_i64;

        for right in 0..=N {
            while !stack.is_empty()
                && (right == N || strength[*stack.last().unwrap()] >= strength[right])
            {
                let pivot = stack.pop().unwrap();
                let pivot_i64 = pivot as i64;

                let left_i64 = stack.last().map(|x| *x as i64 + 1).unwrap_or(0);
                let left = left_i64 as usize;

                let right_i64 = right as i64;

                let left_sum = (MOD + pm_l[pivot + 1]
                    - pm_l[left]
                    - left_i64 * (ps_l[pivot + 1] - ps_l[left]) % MOD)
                    % MOD;

                let right_sum = (MOD + pm_r[pivot + 1]
                    - pm_r[right]
                    - (N_i64 - right_i64) * (ps_r[pivot + 1] - ps_r[right]))
                    % MOD;

                let all_sum =
                    (left_sum * (right_i64 - pivot_i64) + right_sum * (pivot_i64 - left_i64 + 1)) % MOD;

                ans = (ans + all_sum * strength[pivot]) % MOD;
            }
            stack.push(right);
        }
        ans as i32
    }
}
