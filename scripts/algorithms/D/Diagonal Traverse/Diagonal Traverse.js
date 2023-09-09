// Runtime: 188 ms (Top 14.3%) | Memory: 75.58 MB (Top 5.1%)

var findDiagonalOrder = function(matrix) {
    const res = [];
    for (let r = 0, c = 0, d = 1, i = 0, len = matrix.length * (matrix[0] || []).length; i < len; i++) {
        res.push(matrix[r][c]);
        r -= d;
        c += d;
        if (!matrix[r] || matrix[r][c] === undefined) {                 // We've fallen off the...
            if (d === 1) {
                if (matrix[r + 1] && matrix[r + 1][c] !== undefined) {  // ...top cliff
                    r++;
                } else {                                                // ...right cliff
                    r += 2;
                    c--;
                }
            } else {
                if (matrix[r] && matrix[r][c + 1] !== undefined) {      // ...left cliff
                    c++;
                } else {                                                // ...bottom cliff
                    r--;
                    c += 2;
                }
            }
            d = -d;
        }
    }
    return res;
};