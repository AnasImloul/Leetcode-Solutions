var islandPerimeter = function(grid) {
    let perimeter = 0
    let row = grid.length
    let col = grid[0].length
    
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] === 1) {
                if (i === 0 || i > 0 && grid[i-1][j] === 0) perimeter++ 
                if (i === row-1 || i < row-1 && grid[i+1][j] === 0) perimeter++              
                if (j === 0 || j > 0 && grid[i][j-1] === 0) perimeter++
                if (j === col - 1 || j < col && grid[i][j+1] === 0) perimeter++
            }
        }
    }
    
    return perimeter
};
