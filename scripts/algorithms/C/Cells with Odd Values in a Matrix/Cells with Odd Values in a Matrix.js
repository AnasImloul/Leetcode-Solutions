// Runtime: 131 ms (Top 21.83%) | Memory: 44.6 MB (Top 30.28%)
var oddCells = function(m, n, indices) {
    const matrix = Array.from(Array(m), () => Array(n).fill(0));

    let res = 0;
    for (const [r, c] of indices) {
        for (let i = 0; i < n; i++) {
            // toggle 0/1 for even/odd
            // another method: matrix[r][i] = 1 - matrix[r][i]
            // or: matrix[r][i] = +!matrix[r][i]
            matrix[r][i] ^= 1;
            if (matrix[r][i]) res++; else res--;
        }

        for (let i = 0; i < m; i++) {
            matrix[i][c] ^= 1;
            if (matrix[i][c]) res++; else res--;
        }
    }

    return res;
};