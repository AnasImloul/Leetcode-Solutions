// Runtime: 74 ms (Top 20.39%) | Memory: 44.70 MB (Top 31.58%)

var minFallingPathSum = function(matrix) {
    let n = matrix.length;
    let m = matrix[0].length;
    let dp = new Array(n).fill(0).map(() => new Array(m).fill(0));
    
    // tabulation // bottom-up approach
    
    // base case - when i will be 0, dp[0][j] will be matrix[0][j]
    for(let j = 0; j < m; j++) dp[0][j] = matrix[0][j]
    
    for(let i = 1; i < n; i++) {
        for(let j = 0 ; j < m; j++) {
            let up = matrix[i][j] + dp[i - 1][j];
            
            let upLeft = matrix[i][j];
            if((j - 1) >= 0) upLeft += dp[i - 1][j - 1]; // if not out of bound
            else upLeft += 10000; // big enough number
            
            let upRight = matrix[i][j];
            if((j + 1) < m) upRight += dp[i - 1][j + 1]; // if not out of bound
            else upRight += 10000; // big enough number
            
            dp[i][j] = Math.min(up, upLeft, upRight);
        }
    }
    return Math.min(...dp[n - 1]);
};
