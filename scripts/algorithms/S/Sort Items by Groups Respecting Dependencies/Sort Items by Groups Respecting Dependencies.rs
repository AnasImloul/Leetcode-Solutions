// Runtime: 35 ms (Top 22.2%) | Memory: 9.89 MB (Top 25.7%)

use std::collections::{HashMap,VecDeque};
impl Solution {
pub fn sort_items(n: i32, m: i32, group: Vec<i32>, before_items: Vec<Vec<i32>>) -> Vec<i32> {
    let mut outer_graph: HashMap<i32, Vec<i32>> = HashMap::new();
    let mut inner_graph: HashMap<i32, HashMap<i32, Vec<i32>>> = HashMap::new();
    for i in 0..n as usize {
        if group[i] == -1 && before_items[i].is_empty() {
            outer_graph.entry(i as i32).or_default();
        } else if group[i] == -1 {
            outer_graph.entry(i as i32).or_default();
            for b in &before_items[i] {
                let gp = group[*b as usize];
                if gp == -1 {
                    outer_graph.entry(*b).or_default().push(i as i32);
                } else {
                    outer_graph.entry(gp + 40000).or_default().push(i as i32);
                }
            }
        } else {
            outer_graph.entry(group[i] + 40000).or_default();
            inner_graph
                .entry(group[i])
                .or_default()
                .entry(i as i32)
                .or_default();
            for b in &before_items[i] {
                let gp = group[*b as usize];
                if gp == -1 {
                    outer_graph.entry(*b).or_default().push(group[i] + 40000);
                } else if group[i] == gp {
                    inner_graph
                        .entry(gp)
                        .or_default()
                        .entry(*b)
                        .or_default()
                        .push(i as i32);
                } else {
                    outer_graph
                        .entry(gp + 40000)
                        .or_default()
                        .push(group[i] + 40000);
                }
            }
        }
    }
    if let Some(res) = Self::topo_sort(&outer_graph, &inner_graph) {
        if res.len() != n as usize {
            return vec![];
        }
        return res;
    } else {
        return vec![];
    }
}

fn topo_sort(
    graph: &HashMap<i32, Vec<i32>>,
    inner_graph: &HashMap<i32, HashMap<i32, Vec<i32>>>,
) -> Option<Vec<i32>> {
    let mut res: Vec<i32> = vec![];
    let mut in_degree: HashMap<i32, i32> = HashMap::new();
    let mut queue: VecDeque<i32> = VecDeque::new();
    for (k, v) in graph {
        in_degree.entry(*k).or_default();
        for n in v {
            *in_degree.entry(*n).or_default() += 1;
        }
    }
    for (k, v) in &in_degree {
        if *v == 0 {
            queue.push_back(*k);
        }
    }
    while !queue.is_empty() {
        let n = queue.pop_front().unwrap();
        if n < 40000 {
            res.push(n)
        } else {
            if let Some(mut s) = Self::topo_sort(&inner_graph[&(n - 40000)], inner_graph) {
                if s.len() != inner_graph[&(n - 40000)].len() {
                    return None;
                }
                res.append(&mut s);
            } else {
                return None;
            }
        }
        for v in &graph[&n] {
            *in_degree.entry(*v).or_default() -= 1;
            if in_degree[v] == 0 {
                queue.push_back(*v);
            }
        }
    }
    return Some(res);
}
}