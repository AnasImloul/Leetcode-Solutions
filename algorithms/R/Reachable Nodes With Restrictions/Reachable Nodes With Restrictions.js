/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} restricted
 * @return {number}
 */
var reachableNodes = function(n, edges, restricted) {
    const adj = {};
    
    for (const [u, v] of edges) {
        if (adj[u]) {
            adj[u].add(v);
        } else {
            adj[u] = new Set().add(v);
        }
        if (adj[v]) {
            adj[v].add(u);
        } else {
            adj[v] = new Set().add(u);
        }
    }
    
    const restrictedSet = new Set(restricted);
    const visited = new Set();
    
    let ans = 0;
    
    function dfs(node) {
        if (restrictedSet.has(node) || visited.has(node)) {
            return;
        }
        
        ans++;
        visited.add(node);
        
        for (const adjNode of adj[node]) {
            dfs(adjNode);
        }
    }
    
    dfs(0);
    
    return ans;
};
