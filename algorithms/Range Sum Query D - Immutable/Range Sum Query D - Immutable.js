/**
 * @param {number[][]} matrix
 */
var NumMatrix = function(matrix) {
    const n = matrix.length, m = matrix[0].length;
    // n * m filled with 0
    this.prefix = Array.from({ length: n}, (_, i) => {
        return new Array(m).fill(0);
    });
    const prefix = this.prefix;
    // precompute
    for(let i = 0; i < m; i++) {
        if(i == 0) prefix[0][i] = matrix[0][i];
        else prefix[0][i] = prefix[0][i-1] + matrix[0][i];
    }
    for(let i = 0; i < n; i++) {
        if(i == 0) continue;
        else prefix[i][0] = prefix[i-1][0] + matrix[i][0];
    }
    
    for(let i = 1; i < n; i++) {
        for(let j = 1; j < m; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j];
        }
    }
};

/** 
 * @param {number} row1 
 * @param {number} col1 
 * @param {number} row2 
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function(row1, col1, row2, col2) {
    const prefix = this.prefix;
    const biggerRectSum = prefix[row2][col2];
    if(row1 == col1 && row1 == 0) return biggerRectSum;
    if(row1 == 0 || col1 == 0) {
        let subtractRegion = 0;
        if(row1 == 0) subtractRegion = prefix[row2][col1 - 1];
        else subtractRegion = prefix[row1 - 1][col2];
        return biggerRectSum - subtractRegion;
    }
    return biggerRectSum - prefix[row1-1][col2] - prefix[row2][col1 - 1] + prefix[row1-1][col1-1];
};

/** 
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
