var minReorder = function(n, connections) {
    const graph = [];
    const set = new Set();
    
    for (let i = 0; i < n; i++) {
        graph[i] = [];
    }
    
    for (const [u, v] of connections) {
        graph[u].push(v);
        graph[v].push(u);
        set.add(`${u}#${v}`);
    }
    
    let count = 0;
    
    dfs(0, -1)
    
    return count;
    
    
    function dfs(node, parent) {
        
        if (set.has(`${parent}#${node}`)) count++;
        
        for (const nei of graph[node]) {
            if (nei === parent) continue;
       
            dfs(nei, node);
        }
    }
}; 
