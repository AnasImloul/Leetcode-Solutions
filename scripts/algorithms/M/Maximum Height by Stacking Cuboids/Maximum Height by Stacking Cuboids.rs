// Runtime: 2 ms (Top 100.0%) | Memory: 2.08 MB (Top 100.0%)

impl Solution {
    pub fn max_height(cuboids: Vec<Vec<i32>>) -> i32 {
        use std::cmp::*;
        let m = cuboids.len();

        let mut cuboids = cuboids
            .into_iter()
            .map(|mut cub| {
                cub.sort();
                cub.reverse();
                (cub[0], cub[1], cub[2])
            })
            .collect::<Vec<_>>();

        cuboids.sort();
        cuboids.sort_by(|(x1, y1, z1), (x2, y2, z2)| {
            // -- prevent wrong formatting
            if x1 < x2 && y1 < y2 && z1 < z2 {
                Ordering::Greater
            } else {
                Ordering::Less
            }
        });

        let mut ans = vec![(0, 0, 0); m];
        // walk through every pair since n size is only 100 and try 
        // to maximize stack in each position
        ans[0] = cuboids[0];
        for (i, (x, y, z)) in cuboids.into_iter().skip(1).enumerate() {
            for j in 0..=i {
                let prev = ans[j];
                if prev.1 >= y && prev.2 >= z {
                    ans[i + 1] = ans[i + 1].max((x + prev.0, y, z));
                } else {
                    ans[i + 1] = ans[i + 1].max((x, y, z));
                }
            }
        }

        ans.into_iter().map(|(x, _, _)| x).max().unwrap()  
    }
}