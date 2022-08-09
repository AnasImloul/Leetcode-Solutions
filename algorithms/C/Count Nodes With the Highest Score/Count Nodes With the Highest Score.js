var countHighestScoreNodes = function(parents) {
    const n = parents.length;
    const adj = [];
    
    for (let i = 0; i < n; ++i) {
        adj[i] = [];
    } 
    
    for (let i = 1; i < n; ++i) {
        const parent = parents[i];
        adj[parent].push(i);
    }
    
    let maxProd = 0;
    let maxCount = 0;
    
    dfs(0);
    
    return maxCount;
    
    function dfs(node) {
        let rem = n - 1;

        let sum = 0;
        let prod = 1;

        for (const child of adj[node]) {
            const count = dfs(child);
            
            sum += count;
            prod *= count;
            rem -= count;
        }

        if (rem > 0) prod *= rem;

        if (prod > maxProd) {
            maxProd = prod;
            maxCount = 1;
        }
        else if (prod === maxProd) {
            ++maxCount;
        }

        return sum + 1;
    }
};
