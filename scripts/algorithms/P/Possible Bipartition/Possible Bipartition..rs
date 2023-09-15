// Runtime: 23 ms (Top 100.0%) | Memory: 3.19 MB (Top 50.0%)

use std::collections::HashMap;

const FROM: usize = 0;
const TO: usize = 1;
const DEFAULT_FACTION: bool = true;

impl Solution {
    /**
     * Approach: model the "dislikes" as a graph; it is possible to create a
     *           bi-partition iff there is no cycle in the graph.
     * Runtime complexity: O(|V|+|E|)
     * Space complexity:  O(|V|+|E|)
     * N.B.: approach doesn't depend on `n`, but purely on the number of "dislikes".
     */
    pub fn possible_bipartition(n: i32, dislikes: Vec<Vec<i32>>) -> bool {
        if dislikes.is_empty() {
            // If no one dislikes any one, we can create any arbitrary bi-partition.
            return true;
        }
        // Create an undirected graph with all "dislike" relationships (a.k.a. edges).
        // The graph may be sparse, so we use an adjacency list:
        let mut graph = HashMap::new();
        for edge in dislikes.iter() {
            graph.entry(edge[FROM]).or_insert(Vec::new()).push(edge[TO]);
            graph.entry(edge[TO]).or_insert(Vec::new()).push(edge[FROM]);
        }
        // For all nodes involved in a "dislike" relationship, heck if there is a cycle in the graph -- a.k.a. conflict among factions:
        let mut factions = HashMap::new();
        graph.keys().all(|&u| if factions.contains_key(&u) {
            true
        } else {
            no_conflict(u, DEFAULT_FACTION, &mut factions, &graph)
        })
    }
}

/**
 * Run a depth-first search, recursively, and either:
 * - check if there is any conflict with known factions, or
 * - set the faction and recurse, flipping the faction at every step along the way.
 */
fn no_conflict(u: i32, faction: bool, factions: &mut HashMap<i32, bool>, graph: &HashMap<i32, Vec<i32>>) -> bool {
    if let Some(&actual_faction) = factions.get(&u) {
        return actual_faction == faction;
    }
    factions.insert(u, faction);
    graph.get(&u).unwrap().iter().all(|&v| no_conflict(v, !faction, factions, &graph))
}