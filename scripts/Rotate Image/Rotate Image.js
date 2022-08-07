/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;
    
    for (let i = m - 1; i >= 0; i--) {
        for (let j = 0; j < m; j++) {
            matrix[j].push(matrix[i].shift());
        }
    }
};
