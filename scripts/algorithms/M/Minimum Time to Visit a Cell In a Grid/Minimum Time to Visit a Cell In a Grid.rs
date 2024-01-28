// Runtime: 72 ms (Top 100.0%) | Memory: 6.60 MB (Top 33.33%)

use std::collections::BTreeMap;

impl Solution {
    pub fn minimum_time(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut tree: BTreeMap<i32, Vec<(usize, usize)>> = BTreeMap::new();
        tree.insert(0, vec![(0, 0)]);
        grid[0][0] = -1;
        let dir = [0, 1, 0, usize::MAX, 0];
        while let Some(&step) = tree.keys().next() {
            let v = tree.remove(&step).unwrap();
            for &(i, j) in v.iter() {
                for w in dir.windows(2) {
                    let i2 = i.wrapping_add(w[0]);
                    let j2 = j.wrapping_add(w[1]);
                    if i2 < grid.len() && j2 < grid[0].len() {
                        if grid[i2][j2] >= 0 {
                            let step2 = if grid[i2][j2] > step + 1 {
                                grid[i2][j2] + 1 - ((grid[i2][j2] + step) & 1)
                            }
                            else {
                                step + 1
                            };
                            if i2 == grid.len() - 1 && j2 == grid[0].len() - 1 {
                                return step2;
                            }
                            tree.entry(step2).or_default().push((i2, j2));
                            grid[i2][j2] = !grid[i2][j2];
                        }
                    }
                }
            }
            if step == 0 && tree.get(&1).is_none() {
                return -1;
            }
        }
        unreachable!()
    }
}
