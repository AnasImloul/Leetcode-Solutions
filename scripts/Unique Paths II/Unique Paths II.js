var uniquePathsWithObstacles = function(obstacleGrid) {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;
    
    const results = new Array(m).fill(0);
    for (let i = 0; i < m; i++) {
        results[i] = new Array(n).fill(0);
    }
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 && j === 0) {
                results[0][0] = obstacleGrid[0][0] ? 0 : 1;
            } else if (!obstacleGrid[i][j]) {
                const up = i === 0 ? 0 : results[i - 1][j];
                const left = j === 0 ? 0 : results[i][j - 1];
                
                results[i][j] = up + left;
            }   
        }
    }
    
    return results[m - 1][n - 1];
}
