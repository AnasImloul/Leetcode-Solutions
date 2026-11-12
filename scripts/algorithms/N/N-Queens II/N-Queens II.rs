// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 64.29%)

impl Solution {
    pub fn total_n_queens(n: i32) -> i32 {
        if n < 1 { return 0; }

        let mut result = 0;
        Self::_dfs(n, &mut result, 0, 0, 0, 0);
        result
    }
    
    pub fn _dfs(n: i32, result: &mut i32, row: i32, col: i32, pie: i32, na: i32) {
        if row >= n {
            *result += 1;
            return;
        }

        let mut bits = (!(col | pie | na)) & ((1 << n) - 1);
        while bits != 0 {
            let p = bits & -bits;
            Self::_dfs(n, result, row + 1, col | p, (pie | p) << 1, (na | p) >> 1);
            bits = bits & (bits - 1);
        }
    }

}
