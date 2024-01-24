// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 35.29%)

impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        matrix.windows(2).all(|w| w[0].iter().take(w[0].len() - 1).eq(w[1].iter().skip(1)))
    }
}
