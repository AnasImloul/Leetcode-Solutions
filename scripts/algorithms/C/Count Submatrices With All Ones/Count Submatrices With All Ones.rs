// Runtime: 17 ms (Top 57.1%) | Memory: 2.73 MB (Top 14.2%)

impl Solution {
    pub fn num_submat(mat: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (mat.len(), mat[0].len());
        let (mut clm, mut row) = (vec![vec![0; n]; m + 1], vec![vec![0; n + 1]; m]);
        
        for j in 0..n {
            for i in 0..m {
                clm[i + 1][j] = mat[i][j] as usize + clm[i][j];
            }
        }
        
        for i in 0..m {
            for j in 0..n {
                row[i][j + 1] = mat[i][j] as usize + clm[i][j];
            }
        }
        
        let mut ret = 0;
        for i in 0..m {
            for j in 0..n {
                let mut h = m - i;
                for k in j..n {
                    // trying to for a rectangle from [i, j] to [i, k] as base with maximum hight h
                    while h > 0 && clm[i + h][k] - clm[i][k] < h { h -= 1; }
                    if h == 0 { break }
                    ret += h; // we could have h rectangles with same base, but different height
                }
            }
        }
    
        ret as _
    }
}