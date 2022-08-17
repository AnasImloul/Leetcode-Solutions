var checkXMatrix = function(grid) {
    for (let i=0; i<grid.length; i++) {
        for (let j=0; j<grid[i].length; j++) {
            let leftDiagonal = grid[i].length - 1;
            if (i === j && grid[i][j] !== 0 || j === leftDiagonal - i && grid[i][j] !== 0) {
                continue;
            }
            if (i === j && grid[i][j] === 0 || j === leftDiagonal - i && grid[i][j] === 0) {
                return false;
            }
            if (grid[i][j] !== 0) {
                return false;
            }
        }
    }
    return true;
};
