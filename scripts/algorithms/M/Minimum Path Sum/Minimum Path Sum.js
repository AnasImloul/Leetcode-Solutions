// Runtime: 146 ms (Top 15.25%) | Memory: 43.1 MB (Top 76.61%)

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
