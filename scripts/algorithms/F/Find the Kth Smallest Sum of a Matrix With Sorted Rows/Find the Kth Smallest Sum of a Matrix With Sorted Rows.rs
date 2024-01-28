// Runtime: 20 ms (Top 81.82%) | Memory: 4.70 MB (Top 18.18%)

use std::collections::{HashSet,BinaryHeap};

impl Solution {
    pub fn kth_smallest(mat: Vec<Vec<i32>>, k: i32) -> i32 {
        let mut heap = BinaryHeap::new();
        let mut set = HashSet::new();
        let width = mat[0].len() - 1;
        heap.push((-mat.iter().map(|row| row[0]).sum::<i32>(), vec![0;mat.len()]));
        for _ in 1..k {
            let (cur,ind) = heap.pop().unwrap();
            for r in 0..ind.len() {
                if ind[r] < width {
                    let mut tmp = ind.clone();
                    tmp[r] += 1;
                    if !set.contains(&tmp) {
                        set.insert(tmp.clone());
                        heap.push((cur + mat[r][tmp[r] -1] - mat[r][tmp[r]], tmp));
                    }
                }
            }
        }
        -heap.pop().unwrap().0
    }
}
