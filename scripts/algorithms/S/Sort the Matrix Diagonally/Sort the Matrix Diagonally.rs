// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 40.0%)

impl Solution {
    pub fn diagonal_sort(mut mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut buckets = [0; 101];
        let (m, n) = (mat.len(), mat[0].len());

		// Chain together iterators for first element coordinates of all relevant diagonals
        (1..m-1).map(|i| (i, 0)).chain((0..n-1).map(|j| (0, j))).for_each(|(i0, j0)| {
            let (mut i, mut j) = (i0, j0);
            let (mut min, mut max) = (i32::MAX, i32::MIN);
			// Populate buckets for bucket sorting
            while i < m && j < n {
                let element = mat[i][j];
                min = min.min(element);
                max = max.max(element);
                buckets[element as usize] += 1;
                i += 1;
                j += 1;
            }
			// Populate matrix with result of bucket sorting
            let (mut i, mut j) = (i0, j0);
            let mut k = min as usize;
            while i < m && j < n {
                while buckets[k] == 0 {
                    k += 1;
                }
                mat[i][j] = k as i32;
                buckets[k] -= 1;
                i += 1;
                j += 1;
            }
        });
        mat
    }
}
