// Runtime: 2 ms (Top 57.14%) | Memory: 2.40 MB (Top 14.29%)

impl Solution {
    pub fn matrix_block_sum(mat: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let n = mat.len();
        let m = mat[0].len();
        let k = k as usize;
        let mut memo = vec![vec![0;m+1];n+1];
        for i in 0..n {
            for j in 0..m {
                memo[i+1][j+1] = memo[i+1][j] + memo[i][j+1] - memo[i][j] + mat[i][j];
            }
        }
        
        let mut result = vec![vec![0;m];n];
        for i in 0..n {
            for j in 0..m {
                let i_min = i.saturating_sub(k);
                let i_max = std::cmp::min(i+k, n-1);
                let j_min = j.saturating_sub(k);
                let j_max = std::cmp::min(j+k, m-1);

                result[i][j] = memo[i_max+1][j_max+1] - memo[i_max+1][j_min]
                    - memo[i_min][j_max+1] + memo[i_min][j_min];
            }
        }
        result
    }
}
