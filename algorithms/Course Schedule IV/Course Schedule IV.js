var checkIfPrerequisite = function(numCourses, prerequisites, queries) {
    let adj = {};
    for (let [from, to] of prerequisites) {
        if (!adj[from]) {
            adj[from] = [];
        }
        
        adj[from].push(to);
    }
    
    let set = {};
    Object.keys(adj).forEach(key => dfs(key));
    return queries.map(([a,b]) => set[a]?.has(b) || false);
    
    function dfs(cur) {
        if (set[cur]) {
            return set[cur];
        }
        
        if (!set[cur]) {
            set[cur] = new Set();
        }
        
        for (let n of (adj[cur] || [])) {
            set[cur].add(n);
            dfs(n);
            set[n].forEach(set[cur].add, set[cur]);
        }
    }
    
};
