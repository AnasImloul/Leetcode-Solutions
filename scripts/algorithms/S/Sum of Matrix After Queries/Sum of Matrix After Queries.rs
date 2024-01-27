// Runtime: 46 ms (Top 100.0%) | Memory: 5.50 MB (Top 100.0%)

impl Solution {
    pub fn matrix_sum_queries(n: i32, queries: Vec<Vec<i32>>) -> i64 {
        use std::collections::HashSet;
        let (mut res, mut rows_pos, mut cols_pos) = (0i64, HashSet::new(), HashSet::new());
        for i in (0..queries.len()).rev() {
            let (query_type, pos, v) = (queries[i][0], queries[i][1], queries[i][2]);
            if query_type == 0 && !rows_pos.contains(&pos) {
                rows_pos.insert(pos);
                res += (n as i64 - cols_pos.len() as i64) * (v as i64);
            } else if query_type == 1 && !cols_pos.contains(&pos) {
                cols_pos.insert(pos);
                res += (n as i64 - rows_pos.len() as i64) * (v as i64);
            }
        }

        res
    }
}
