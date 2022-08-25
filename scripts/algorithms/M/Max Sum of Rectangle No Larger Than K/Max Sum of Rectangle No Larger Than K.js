// Runtime: 1009 ms (Top 33.33%) | Memory: 44.6 MB (Top 55.56%)
/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var maxSumSubmatrix = function(matrix, k) {
    if (!matrix.length) return 0;

    let n = matrix.length, m = matrix[0].length;
    let sum = new Array(n + 1).fill(0).map(a => new Array(m + 1).fill(0));
    let ans = -Infinity;

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            for(let x = 1; x <= i; ++x) {
                for(let y = 1; y <= j; ++y) {
                    let s = rangeSum(sum, x, y, i, j);
                    if (s <= k) {
                        ans = Math.max(s, ans);
                    }
                }
            }
        }
    }
    return ans;
}

const rangeSum = (sum, x1, y1, x2, y2) => {
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}