var minPathCost = function(grid, moveCost) {
    const rows = grid.length;
    const cols = grid[0].length;

    const cache = [];
    
    for (let i = 0; i < rows; i++) {
        cache.push(Array(cols).fill(null));
    }
    
    function move(row, col) {
        const val = grid[row][col];
        
        if (cache[row][col] !== null) {
            return cache[row][col];
        }
        
        if (row === rows - 1) {
            return val;
        }
        
        let ans = Number.MAX_SAFE_INTEGER;

        for (let i = 0; i < cols; i++) {
            const addCost = moveCost[val][i];

            ans = Math.min(ans, move(row + 1, i) + val + addCost);
        }
        
        cache[row][col] = ans;
        
        return ans;
    }

    let ans = Number.MAX_SAFE_INTEGER;
    
    for (let i = 0; i < cols; i++) {
        ans = Math.min(ans, move(0, i));
    }
    
    return ans;
};
