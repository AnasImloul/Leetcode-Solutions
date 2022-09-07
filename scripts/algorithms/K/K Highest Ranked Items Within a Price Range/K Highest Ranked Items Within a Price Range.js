// Runtime: 960 ms (Top 100.00%) | Memory: 134.1 MB (Top 85.71%)
var highestRankedKItems = function(grid, pricing, start, k) {
    const m = grid.length;
    const n = grid[0].length;
    const dirs = [-1, 0, 1, 0, -1];

    const visited = [];

    for (let i = 0; i < m; ++i) {
        visited[i] = new Array(n).fill(false);
    }

    const [low, high] = pricing;

    const queue = [];

    queue.push([...start, 0]);

    const items = [];

    while (queue.length > 0) {
        const [row, col, dist] = queue.shift();

        if (visited[row][col]) continue;

        visited[row][col] = true;

        const price = grid[row][col];

        if (withinRange(price, low, high)) {
            items.push({ dist, price, row, col });
        }

        for (let i = 0; i < dirs.length - 1; ++i) {
            const neiRow = row + dirs[i];
            const neiCol = col + dirs[i + 1];

            if (withinBound(neiRow, neiCol) && !visited[neiRow][neiCol] && grid[neiRow][neiCol] != 0) {
                queue.push([neiRow, neiCol, dist + 1]);
            }
        }
    }

    items.sort(compareFunc);

    const res = [];

    for (let i = 0; i < Math.min(k, items.length); ++i) {
        const { dist, price, row, col } = items[i];

        res.push([row, col]);
    }

    return res;

    function withinRange(price, low, high) {
        return low <= price && price <= high;
    }

    function withinBound(row, col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }

    function compareFunc(a, b) {
        return a.dist - b.dist || a.price - b.price || a.row - b.row || a.col - b.col;
    }
};