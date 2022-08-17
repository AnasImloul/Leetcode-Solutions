/**
 * @param {number[][]} grid
 * @param {number} stampHeight
 * @param {number} stampWidth
 * @return {boolean}
 */
var possibleToStamp = function(grid, stampHeight, stampWidth) {
    const w = grid[0].length;
    const h = grid.length;
    
    // dp[i + 1][j + 1] - sum of cells in the rectangle, where 
    // (0, 0) is the left upper corner in the matrix, 
    // (i, j) is the rigth down corner in the matrix
    function getSumOfRectangle(matrix) {
        const h = matrix.length;
        const w = matrix[0].length;
        const dp = new Array(h + 1);
        dp[0] = new Array(w + 1).fill(0);
        for (let i = 0; i < h; i++) {
            dp[i + 1] = new Array(w + 1);
            dp[i + 1][0] = 0;
            for (let j = 0; j < w; j++) {
                dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + matrix[i][j];
            }
        } 
        return dp;
    }
    

    const dp = getSumOfRectangle(grid);
    
    // diff[i][j] === 1 <- start of the stamp (its left upper corner is in point (i, j))
    // diff[i][j] === -1 <- a border of the stamp 
    // (its corner is either (i, j - 1) or (i - 1, j) or (i - 1, j - 1))
    const diff = new Array(h + 1);
    
    // 1) fill diff with zeros
    for (let i = 0; i <= h; i++) {
        diff[i] = new Array(w + 1).fill(0);
    }
    
    for (let i = 0; i <= h - stampHeight; i++) {
        for (let j = 0; j <= w - stampWidth; j++) {
            // isFitPossible === 0 <- we can put the stamp, 
            // such that its left upper corner is in point (i, j)
            // isFitPossible > 0 <- we can't put the stamp, 
            // such that its left upper corner is in point (i, j)
            const isFitPossible = 
                  dp[i + stampHeight][j + stampWidth] 
                  - dp[i + stampHeight][j]
                  - dp[i][j + stampWidth]
                  + dp[i][j]
            
            if (isFitPossible === 0) {
                diff[i][j] += 1;
                diff[i][j + stampWidth] += -1;
                diff[i + stampHeight][j] += -1;
                diff[i + stampHeight][j + stampWidth] += 1;
            }
        }  
    }
    
    const dp2 = getSumOfRectangle(diff);
    for (let i = 0; i < h; i++) {
        for (let j = 0; j < w; j++) {
            if (dp2[i + 1][j + 1] === 0 && grid[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
};
