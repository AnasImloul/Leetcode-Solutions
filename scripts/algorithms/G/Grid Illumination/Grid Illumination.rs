// Runtime: 52 ms (Top 100.0%) | Memory: 6.10 MB (Top 100.0%)

use std::collections::hash_map::{Entry, OccupiedEntry};
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn grid_illumination(n: i32, lamps: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let (mut rows, mut cols, mut digL, mut digR, mut lamps) = lamps.iter().fold(
            (
                HashMap::new(),
                HashMap::new(),
                HashMap::new(),
                HashMap::new(),
                HashSet::new(),
            ),
            |(mut rows, mut cols, mut digL, mut digR, mut lamps), l| {
                if lamps.insert((l[0], l[1])) {
                    *rows.entry(l[0]).or_default() += 1;
                    *cols.entry(l[1]).or_default() += 1;
                    *digL.entry(l[0] - l[1]).or_default() += 1;
                    *digR.entry(l[0] + l[1]).or_default() += 1;
                }
                (rows, cols, digL, digR, lamps)
            },
        );

        queries
            .iter()
            .map(|q| {
                if !rows.contains_key(&q[0])
                    && !cols.contains_key(&q[1])
                    && !digL.contains_key(&(q[0] - q[1]))
                    && !digR.contains_key(&(q[0] + q[1]))
                {
                    return 0;
                }
                for i in (q[0] - 1).max(0)..=(q[0] + 1).min(n - 1) {
                    for j in ((q[1] - 1).max(0)..=(q[1] + 1).min(n - 1))
                        .filter(|&j| lamps.remove(&(i, j)))
                    {
                        match (
                            rows.entry(i),
                            cols.entry(j),
                            digL.entry(i - j),
                            digR.entry(i + j),
                        ) {
                            (
                                Entry::Occupied(ro),
                                Entry::Occupied(co),
                                Entry::Occupied(dl),
                                Entry::Occupied(dr),
                            ) => {
                                let arr = [ro, co, dl, dr];
                                for mut e in arr {
                                    let mut v = e.get_mut();
                                    match *v {
                                        1 => {
                                            e.remove();
                                        }
                                        _ => *v -= 1,
                                    }
                                }
                            }
                            _ => unreachable!(),
                        }
                    }
                }
                1
            })
            .collect()
    }
}

