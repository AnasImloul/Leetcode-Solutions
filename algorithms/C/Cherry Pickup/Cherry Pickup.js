var cherryPickup = function(grid) {
    let result = 0, N = grid.length, cache = {}, cherries;
    
    const solve = (x1, y1, x2, y2) => {
        if(x1 === N -1 && y1 === N-1) 
            return grid[x1][y1] !== -1 ? grid[x1][y1] : -Infinity;
        if(x1 > N -1 || y1 > N-1 || x2 > N-1 || y2 > N-1 || grid[x1][y1] === -1 ||grid[x2][y2] === -1) 
            return -Infinity;
        
        let lookup_key = `${x1}:${y1}:${x2}:${y2}`;
        if(cache[lookup_key]) return cache[lookup_key];
        
        if(x1 === x2 && y1 === y2) 
            cherries = grid[x1][y1];
        else
            cherries = grid[x1][y1] + grid[x2][y2];
        
        result = cherries + Math.max(solve(x1 + 1, y1, x2 + 1, y2),
                solve(x1, y1 + 1, x2, y2 + 1),
                solve(x1 + 1, y1, x2, y2 + 1),
                solve(x1, y1 + 1, x2 + 1, y2));
        
        cache[lookup_key] = result;
        return result;
    };
    
    result = solve(0, 0, 0, 0);
    return result > 0 ? result : 0;
};
