var maxEqualRowsAfterFlips = function(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const map = new Map();
    let max = 0;
    
    for (let i = 0; i < m; i++) {
        let normal = 0;
        let reversed = 0;
        
        for (let j = 0; j < n; j++) {
            normal = normal << 1 | matrix[i][j];
            reversed = reversed << 1 | (1 - matrix[i][j]);
        }
        
        if (!map.has(normal)) map.set(normal, 0);
        map.set(normal, map.get(normal) + 1);
        max = Math.max(max, map.get(normal));
        
        if (!map.has(reversed)) map.set(reversed, 0);
        map.set(reversed, map.get(reversed) + 1);
        max = Math.max(max, map.get(reversed));
    }
    
    return max;
};
