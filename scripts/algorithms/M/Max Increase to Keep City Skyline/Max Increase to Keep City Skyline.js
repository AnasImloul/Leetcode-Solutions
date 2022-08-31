// Runtime: 73 ms (Top 92.50%) | Memory: 42.7 MB (Top 88.33%)
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxIncreaseKeepingSkyline = function(grid) {
    let n = grid.length;
    let sum = 0;
    let cache = [];

    for (let i = 0; i < n; i++) {
        const rowMax = Math.max(...grid[i]);

        for (let j = 0; j < n; j++) {
            let colMax = cache[j];

            if (!colMax) {
                let max = Number.MIN_SAFE_INTEGER;
                for (let c = 0; c < n; c++) {
                    max = Math.max(max, grid[c][j]);
                }
                cache[j] = max;
                colMax = max;
            }

            sum += Math.min(rowMax, colMax) - grid[i][j];
        }
    }

    return sum;
};