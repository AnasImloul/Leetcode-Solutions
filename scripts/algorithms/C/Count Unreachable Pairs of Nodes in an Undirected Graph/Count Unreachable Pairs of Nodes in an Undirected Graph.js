var countPairs = function(n, edges) {
    const adj = [];

    for (let i = 0; i < n; i++) {
        adj.push([]);
    }
    
    for (let [from, to] of edges) {
        adj[from].push(to);
        adj[to].push(from);
    }
    
    const visited = new Set();

    function dfs(from) {
        visited.add(from);

        let count = 1;

        for (const to of adj[from]) {
            if (!visited.has(to)) {
                count += dfs(to);
            }
        }
        
        return count;
    }

    const groups = [];
        
    for (let i = 0; i < n; i++) {
        if (!visited.has(i)) {
            const count = dfs(i);
            groups.push(count);
        }
    }
    
    let ans = 0;
    
    for (let i = 0; i < groups.length - 1; i++) {
        for (let j = i + 1; j < groups.length; j++) {
            ans += groups[i] * groups[j];
        }
    }
    
    return ans;
};
