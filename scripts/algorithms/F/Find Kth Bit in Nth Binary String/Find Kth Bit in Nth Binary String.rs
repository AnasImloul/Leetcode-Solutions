// Runtime: 40 ms (Top 50.0%) | Memory: 4.04 MB (Top 100.0%)

impl Solution {
    pub fn find_kth_bit(n: i32, k: i32) -> char {
        let n = n as usize;
        let k = k as usize;
        let mut arr = vec![vec![]; n];

        arr[0].push(false);
        for i in 1..n {
            let len = arr[i - 1].len();
            for j in 0..len {
                let v = arr[i - 1][j];
                arr[i].push(v);
            }
            arr[i].push(true);
            for j in (0..len).rev() {
                let v = !arr[i - 1][j];
                arr[i].push(v);
            }
        }

        if arr[n - 1][k - 1] {
            '1'
        } else {
            '0'
        }
    }
}