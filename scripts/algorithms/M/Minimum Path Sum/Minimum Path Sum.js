// Runtime: 65 ms (Top 97.08%) | Memory: 42.8 MB (Top 85.83%)
var minPathSum = function(grid) {
    let row = grid.length;
    let col = grid[0].length;

    for(let i = 1; i < row; i++) {
        grid[i][0] += grid[i-1][0];
    }
    for(let j = 1; j < col; j++) {
        grid[0][j] += grid[0][j-1];
    }
    for(let i = 1; i < row; i++) {
        for(let j = 1; j < col; j++) {
            grid[i][j] += Math.min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[row-1][col-1];
};
