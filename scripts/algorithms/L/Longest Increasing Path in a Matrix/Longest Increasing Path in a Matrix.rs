// Runtime: 8 ms (Top 84.0%) | Memory: 2.46 MB (Top 64.0%)

impl Solution {
    pub fn longest_increasing_path(matrix: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (matrix.len(), matrix[0].len());
        let mut cache = vec![vec![None; n]; m];
        let mut answer = 0;
        for i in 0..m {
            for j in 0..n {
                answer = answer.max(Self::dfs(&matrix, &mut cache, i, j));
            }
        }
        answer
    }
    fn dfs(matrix: &[Vec<i32>], cache: &mut Vec<Vec<Option<i32>>>, i: usize, j: usize) -> i32 {
        if let Some(c) = cache[i][j] {
            return c;
        }
        let (m, n) = (matrix.len(), matrix[0].len());
        let mut ret = 1;
        for d in [0, -1, 0, 1, 0].windows(2) {
            let (ni, nj) = (i as i32 + d[0], j as i32 + d[1]);
            if (0..m as i32).contains(&ni) && (0..n as i32).contains(&nj) {
                let (ni, nj) = (ni as usize, nj as usize);
                if matrix[ni][nj] > matrix[i][j] {
                    ret = ret.max(Self::dfs(matrix, cache, ni, nj) + 1);
                }
            }
        }
        cache[i][j] = Some(ret);
        ret
    }
}