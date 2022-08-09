var minCost = function(houses, cost, m, n, target) {
    let map = new Map();

    function dfs(idx = 0, prevColor = -1, neighborhoods = 0) {
        if (idx === m) return neighborhoods === target ? 0 : Infinity;

        let key = `${idx}-${prevColor}-${neighborhoods}`;
        if (map.has(key)) return map.get(key);
        
        let color = houses[idx];
        // If the current house is already painted
        if (color > 0) {
            return color !== prevColor ? dfs(idx + 1, color, neighborhoods + 1) : dfs(idx + 1, color, neighborhoods);
        }

        let minCost = Infinity;
        for (let i = 1; i <= n; i++) {
            let potentialCost;
            // If color i is !== prevColor, increment the neighborhood count
            if (i !== prevColor) potentialCost = dfs(idx + 1, i, neighborhoods + 1);
            // Otherwise, the neighborhood simply expanded so the neighborhood count stays the same
            else potentialCost = dfs(idx + 1, i, neighborhoods);
            
            if (potentialCost === Infinity) continue;
            minCost = Math.min(minCost, cost[idx][i - 1] + potentialCost);
        }
        map.set(key, minCost);
        return minCost;
    }
    
    let minCost = dfs();
    return minCost === Infinity ? -1 : minCost;
};
