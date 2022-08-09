var countSubIslands = function(grid1, grid2) {
    const R = grid2.length, C = grid2[0].length;
    
    // returns no of cells in grid 2 not covered in grid1
    function noOfNotCoveredDfs(i, j) {
        if (i < 0 || j < 0) return 0;
        if (i >= R || j >= C) return 0;
        if (grid2[i][j] !== 1) return 0;
        
        // mark visited
        grid2[i][j] = 2;
        
        return (grid1[i][j] === 1 ? 0 : 1) + 
            noOfNotCoveredDfs(i - 1, j) + 
            noOfNotCoveredDfs(i + 1, j) + 
            noOfNotCoveredDfs(i, j - 1) + 
            noOfNotCoveredDfs(i, j + 1);
    }
    
    let ans = 0;
    for (let i = 0; i < R; i++) {
        for (let j = 0; j < C; j++) {
            if (grid2[i][j] === 1) {
                if (noOfNotCoveredDfs(i, j) === 0) {
                    ans++;
                }
            }
        }
    }
    
    return ans;
};
