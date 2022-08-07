var minimumTotal = function(triangle) {
    const memo = {};
    
    function minPath(row, col) {
        let key = `${row}:${col}`;
        
        if (key in memo) {
            return memo[key];
        }
        
        let path = triangle[row][col];
        
        if (row < triangle.length - 1) {
            path += Math.min(minPath(row + 1, col), minPath(row + 1, col + 1));
        }
        
        memo[key] = path;
        
        return path;
    }
    
    return minPath(0, 0);
};
