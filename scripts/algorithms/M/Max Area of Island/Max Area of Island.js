// Runtime: 135 ms (Top 39.40%) | Memory: 45 MB (Top 74.80%)
var maxAreaOfIsland = function(grid) {
    let result = 0;
    const M = grid.length;
    const N = grid[0].length;
    const isOutGrid = (m, n) => m < 0 || m >= M || n < 0 || n >= N;
    const island = (m, n) => grid[m][n] === 1;
    const dfs = (m, n) => {
        if (isOutGrid(m, n) || !island(m, n)) return 0;

        grid[m][n] = 'X';
        const top = dfs(m - 1, n);
        const bottom = dfs(m + 1, n);
        const left = dfs(m, n - 1);
        const right = dfs(m, n + 1);
        return 1 + top + bottom + left + right;
    };

    for (let m = 0; m < M; m++) {
        for (let n = 0; n < N; n++) {
            if (!island(m, n)) continue;
            const area = dfs(m, n);

            result = Math.max(area, result);
        }
    }
    return result;
};