/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[][]}
 */
var matrixBlockSum = function(mat, k) {
    let sum = 0;
    let dp = Array(mat.length + 1);
    dp[0] = Array(mat[0].length).fill(0);
    
    // sum of row el
    for (let i = 0; i < mat.length; i++){
        dp[i + 1] = Array(mat[0].length).fill(0);
        for (let j = 0; j < mat[0].length; j++){
            dp[i + 1][j] += mat[i][j] + sum;
            sum = dp[i + 1][j];
        }
        sum = 0;
    }
    
    // sum of col el
    for (let j = 0; j < mat[0].length; j++){
        for (let i = 0; i < mat.length; i++){
            dp[i + 1][j] += sum;
            sum = dp[i + 1][j];
        }
        sum = 0;
    }
    
    dp = dp.slice(1);
    
    // cal sum of blocks
    for (let i = 0; i < mat.length; i++){
        let r1 = Math.max(0, i - k);
        let r2 = Math.min(mat.length - 1, i + k);
        for (let j = 0; j < mat[0].length; j++){
            let c1 = Math.max(0, j - k);
            let c2 = Math.min(mat[0].length - 1, j + k);
            
            let value = dp[r2][c2];
            
            if (r1 - 1 >= 0){
                value -= dp[r1 - 1][c2];
            }
            if (c1 - 1 >= 0){
                value -= dp[r2][c1 - 1]
            }
            if (r1 - 1 >= 0 && c1 - 1 >= 0){
                value += dp[r1 - 1][c1 - 1];
            }
            mat[i][j] = value;
        }
    }
    
    return mat;
    
};
