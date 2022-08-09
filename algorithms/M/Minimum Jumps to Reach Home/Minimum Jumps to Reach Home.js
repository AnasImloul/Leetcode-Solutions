var minimumJumps = function(forbidden, a, b, x) {
    let f = new Set(forbidden);
    let m = 2000 + 2 * b;
    let memo = {};
    let visited = new Set();
    let res = dfs(0, true);
    return res === Infinity ? -1 : res;
    
    function dfs(i,canJumpBack) {
        if (i === x) return 0;
        let key = `${i},${canJumpBack}`;
        visited.add(i);
        if (memo[key] !== undefined) return memo[key];
        if (i > m || i < 0) return Infinity;
        let min = Infinity;
        if (canJumpBack && !f.has(i - b) && !visited.has(i-b)) {
            min = Math.min(min, 1 + dfs(i - b, false));
        }
        
        if (!f.has(i + a) && !visited.has(i+a)) {
            min = Math.min(min, 1 + dfs(i + a, true));
        }
        
        visited.delete(i);
        return memo[key] = min;
    }
};
