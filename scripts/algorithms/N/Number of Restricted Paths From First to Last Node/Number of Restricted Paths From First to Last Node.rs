// Runtime: 94 ms (Top 100.0%) | Memory: 8.64 MB (Top 100.0%)

use std::collections::{HashSet, BinaryHeap, HashMap};


impl Solution {
    
    pub fn find_restricted(node: usize, shortest_path: &Vec<i32>, graph: &Vec<Vec<(usize, i32)>>, memo: &mut HashMap<usize, i32>) -> i32 {
        let last_node = shortest_path.len()-1;
        if node == last_node {
            return 1;
        }
        
        if memo.contains_key(&node) {
            return *memo.get(&node).unwrap();
        }
        
        let mut pathes = 0;
        let MOD = i32::pow(10, 9) + 7;
        
        for edge in &graph[node] {
            let neighbor = edge.0;
            if shortest_path[neighbor] >= shortest_path[node] && neighbor != last_node {
                continue;
            }
            pathes += Solution::find_restricted(neighbor, shortest_path, graph, memo);
            pathes %= MOD;
        }
        
        memo.insert(node, pathes);
        return pathes;
    }
    
    
    // O(n) time,
    // O(n) space,
    // Approach: djikstra shortest path, dp, top down dp, heap, 
    pub fn count_restricted_paths(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut graph = vec![Vec::new();n as usize+1];
        
        for edge in edges {
            let node1 = edge[0] as usize;
            let node2 = edge[1] as usize;
            let weight = edge[2];
            
            graph[node1].push((node2, weight));
            graph[node2].push((node1, weight));
        }
        
        let mut shortest_dist = vec![0;n as usize +1];
        let mut min_heap = BinaryHeap::new();
        let mut visited: HashSet<usize> = HashSet::new();
        
        min_heap.push((0, n as usize));
        // calulate shortest path using djikstra
        while min_heap.len() > 0 {
            let popped = min_heap.pop().unwrap();
            let dist = -popped.0;
            let node = popped.1 as usize;
            
            if visited.contains(&node) {
                continue;
            }
            visited.insert(node);
            shortest_dist[node] = dist;
            
            for edge in &graph[node] {
                if visited.contains(&edge.0) {
                    continue;
                }
                let new_dist = -(dist+edge.1);
                min_heap.push((new_dist, edge.0));
            }
            
        }
        
        return Solution::find_restricted(1, &shortest_dist, &graph, &mut HashMap::new());
    }
}