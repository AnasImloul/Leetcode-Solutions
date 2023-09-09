// Runtime: 16 ms (Top 34.1%) | Memory: 6.22 MB (Top 5.9%)

impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let mut hs = heights.clone();
        hs.push(0);
        hs.insert(0, 0);

        fn bounds(hs: &Vec<i32>) -> Vec<usize> {
            let mut left = vec![0; hs.len()];
            for i in 1..hs.len() {
                left[i] = if hs[i] > hs[i - 1] {
                    i - 1
                }
                else if hs[i] == hs[i - 1] {
                    left[i - 1]
                }
                else {
                    let mut j = left[i - 1];
                    while j >= 0 && hs[j] >= hs[i] && j != left[j] {
                        j = left[j];
                    }
                    j
                };
            }
            left
        }
        let rs: Vec<i32> = hs.clone().into_iter().rev().collect();
        let bounds_l = bounds(&hs);
        let bounds_r: Vec<usize> =
            bounds(&rs).into_iter().rev().map(|i| hs.len() - 1 - i).collect();
        bounds_l.iter().zip(bounds_r.iter()).enumerate().map(|(i, (l, r))| {
            (r - l - 1) * hs[i] as usize
        }).max().unwrap() as i32
    }
}