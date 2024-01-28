// Runtime: 68 ms (Top 83.33%) | Memory: 8.60 MB (Top 100.0%)

use std::collections::BinaryHeap;
use std::cmp::Reverse;

pub fn to_graph(
    edges: &Vec<(usize, usize)>,
    scores: &Vec<u32>,
) -> Vec<Vec<usize>> {
    const HEAP_THRESHOLD: usize = 3;

    let n = scores.len();

    let mut ret = vec![BinaryHeap::new(); n];

    for &(v0, v1) in edges {
        let e0 = scores[v0];
        let e1 = scores[v1];

        ret[v0].push(Reverse((e1, v1)));
        ret[v1].push(Reverse((e0, v0)));

        if ret[v0].len() > HEAP_THRESHOLD {
            ret[v0].pop();
        }
        if ret[v1].len() > HEAP_THRESHOLD {
            ret[v1].pop();
        }
    }

    ret.into_iter()
        .map(|heap| {
            heap.into_iter()
                .map(|e| e.0.1)
                .collect::<Vec<_>>()
        })
        .collect::<Vec<_>>()
}

impl Solution {
    pub fn maximum_score(scores: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
        let scores = scores.into_iter()
            .map(|e| e as u32)
            .collect::<Vec<_>>();
        let edges = edges.into_iter()
            .filter(|v| v.len() == 2)
            .map(|v| {
                v.into_iter()
                    .map(|e| e as usize)
                    .collect::<Vec<_>>()
            })
            .map(|v| (v[0], v[1]))
            .filter(|(v0, v1)| v0 != v1)
            .collect::<Vec<_>>();
        let graph = to_graph(&edges, &scores);

        let mut ret = None;
        for (v0, v1) in edges {
            let mut _ret = None;
            for v0_next in graph[v0].clone() {
                if v0_next == v1 { continue; }
                let e0_next = scores[v0_next];
                for v1_next in graph[v1].clone() {
                    if v1_next == v0 { continue; }
                    if v0_next == v1_next { continue; }
                    let e1_next = scores[v1_next];
                    _ret = Some(_ret.unwrap_or(u32::MIN).max(e0_next + e1_next));
                }
            }
            let mut _ret = if let Some(inner) = _ret {
                inner
            } else { continue; };
            _ret += scores[v0];
            _ret += scores[v1];

            ret = Some(ret.unwrap_or(u32::MIN).max(_ret));
        }

        ret.map(|e| e as i32)
            .unwrap_or(-1)
    }
}
