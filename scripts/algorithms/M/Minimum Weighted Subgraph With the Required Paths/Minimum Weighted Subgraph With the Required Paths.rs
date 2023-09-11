// Runtime: 84 ms (Top 100.0%) | Memory: 24.78 MB (Top 75.0%)

use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn minimum_weight(n: i32, edges: Vec<Vec<i32>>, src1: i32, src2: i32, dest: i32) -> i64 {
        let n = n as usize;
        let (mut graph, mut graph_reverse) = (vec![vec![]; n], vec![vec![]; n]);
        for e in edges {
            let (u, v, w) = (e[0] as usize, e[1] as usize, e[2] as i64);
            graph[u].push((v, w));
            graph_reverse[v].push((u, w));
        }

        let (mut d1, mut d2, mut d3) = (vec![i64::MAX; n], vec![i64::MAX; n], vec![i64::MAX; n]);
        Self::calculate(&graph, &mut d1, src1 as usize);
        Self::calculate(&graph, &mut d2, src2 as usize);
        Self::calculate(&graph_reverse, &mut d3, dest as usize);

        let mut ret = i64::MAX;
        for u in 0 .. n {
            if d1[u] == i64::MAX || d2[u] == i64::MAX || d3[u] == i64::MAX { continue }
            ret = ret.min(d1[u] + d2[u] + d3[u]);
        } 
        
        if ret == i64::MAX { -1 } else { ret } 
    }

    fn calculate(graph: &Vec<Vec<(usize, i64)>>, dist: &mut Vec<i64>, src: usize) {
        let mut pq = BinaryHeap::new();
        
        pq.push(Reverse((0i64, src)));
        dist[src] = 0;
        while let Some(Reverse((d, u))) = pq.pop() {
            if dist[u] < d { continue }
            
            for (v, w) in &graph[u] {
                let (v, w) = (*v, *w);
                if dist[v] <= d + w { continue }
                
                dist[v] = d + w;
                pq.push(Reverse((d + w, v)));
            }
        }
    }
}