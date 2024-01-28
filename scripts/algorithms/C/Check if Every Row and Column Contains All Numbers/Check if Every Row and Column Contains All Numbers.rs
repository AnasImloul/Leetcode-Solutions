// Runtime: 17 ms (Top 90.0%) | Memory: 2.30 MB (Top 85.0%)

impl Solution {
    pub fn check_valid(matrix: Vec<Vec<i32>>) -> bool {
        let n = matrix.len();
        (0..n)
            .all(|col_index| {
                let mut sorted_col = matrix
                    .iter()
                    .map(|row| {
                        row[col_index]
                    })
                    .collect::<Vec<i32>>();
                sorted_col.sort();
                sorted_col
                    .into_iter()
                    .eq((1..=n as i32))
            })
        &&
        matrix
            .iter()
            .all(|row| {
                let mut sorted_row = row.clone();
                sorted_row.sort();
                sorted_row
                    .into_iter()
                    .eq((1..=n as i32))
            })

    }
}
