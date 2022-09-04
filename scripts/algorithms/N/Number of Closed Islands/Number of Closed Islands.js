// Runtime: 118 ms (Top 50.00%) | Memory: 44.6 MB (Top 73.90%)
/**
 * @param {number[][]} grid
 * @return {number}
 */
var closedIsland = function(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let islandCount = 0; // Initial island count

    // For Quick Response
    if (rows <= 2 || cols <= 2) return islandCount;

    for (let i = 0; i <= rows - 1; i++) {
        for (let j = 0; j <= cols - 1; j++) {
            /*
                If land was found on the border, it can never be enclosed by water.
                So, mark the all the adjacent land across grid as visited.
            */
            if (grid[i][j] === 0 && (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)) {
                dfs(i, j);
            }
        }
    }

    // If land is found, increase the count and walk around land(adjacent indexes) to mark them as visited.
    for (let i = 1; i <= rows - 1; i++) {
        for (let j = 1; j <= cols - 1; j++) {
            if (grid[i][j] === 0) {
                islandCount++;
                dfs(i, j);
            }
        }
    }

    // To walk around land and mark it as visited
    function dfs(x, y) {
        if (x < 0 || y < 0 || x >= rows || y >= cols) return;
        if (grid[x][y] !== 0) return;

        grid[x][y] = 2;

        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x - 1, y);
        dfs(x, y - 1);
    }

    return islandCount;
};