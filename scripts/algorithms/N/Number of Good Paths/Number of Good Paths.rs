// Runtime: 127 ms (Top 100.0%) | Memory: 12.30 MB (Top 100.0%)

use std::collections::HashMap;

impl Solution {
    pub fn number_of_good_paths(vals: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
        let n = vals.len();
        let mut uf: Vec<_> = (0..n).collect();
        let mut edges: Vec<_> = edges.into_iter().map(|e| {
            let (n1, n2) = (e[0] as usize, e[1] as usize);
            (vals[n1].max(vals[n2]), n1, n2)
        }).collect();
        edges.sort_unstable();
        let mut counts = (0..n).map(|i| (i, std::iter::once((vals[i], 1)).collect::<HashMap<_,_>>())).collect::<HashMap<_, _>>();
        let mut rez = n;

        fn find(i: usize, uf: &mut Vec<usize>) -> usize {
            if uf[i] == i {
                i
            } else {
                uf[i] = find(uf[i], uf);
                uf[i]
            }
        }

        for (val, n1, n2) in edges {
            let (r1, r2) = (find(n1, &mut uf), find(n2, &mut uf));
            let (c1, c2) = (counts.get(&r1).unwrap().get(&val).copied().unwrap_or(0), counts.get(&r2).unwrap().get(&val).copied().unwrap_or(0));
            rez += c1 * c2;
            uf[r2] = r1;
            *counts.get_mut(&r1).unwrap().entry(val).or_default() += c2
        }

        rez as _
    }
}
