var countServers = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    
    const lastRows = [];
    const lastCols = [];
    
    const set = new Set();
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {                
                const currIdx = (i * n) + j;
               
                const rowNeiIdx = lastRows[i];
                
                if (rowNeiIdx != null) {
                    set.add(currIdx).add(rowNeiIdx);
                }
                
                const colNeiIdx = lastCols[j];
                
                if (colNeiIdx != null) {
                    set.add(currIdx).add(colNeiIdx);
                }
                
                lastRows[i] = currIdx;
                lastCols[j] = currIdx;
            }
        }
    }
    
    return set.size; 
};
