var possibleBipartition = function(n, dislikes) {
    const g = new Map();
    dislikes.forEach(([a, b]) => {
        const aDis = g.get(a) || [];
        const bDis = g.get(b) || [];
        g.set(a, aDis.concat(b));
        g.set(b, bDis.concat(a));
    });
    
    const vis = new Array(n+1).fill(false);
    const col = new Array(n+1).fill(-1);
    
    const dfs = (n, c = 0) => {
        if(vis[n]) return true;
        
        col[n] = c;
        vis[n] = true;
        
        const nodes = g.get(n) || [];
        for(let node of nodes) {
            if(!vis[node]) {
                if(!dfs(node, 1 - c)) return false;
            }
            
            if(node != n && col[node] == c) return false;
        }
        
        return true;
    };
    
    let canBi = true;
    for(let i = 1; i <= n; i++) {
        canBi &= dfs(i);
    }
    return canBi;
};
