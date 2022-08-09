let directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];

var minDays = function(grid) {
    let colorNumber = 2;
    let landCells = [];
    
    function colorIsland(i, j) {
        grid[i][j] = colorNumber;
        for(let k = 0; k < directions.length; k++) {
            let newI = i + directions[k][0];
            let newJ = j + directions[k][1];
            
            if(newI >= 0 && newJ >= 0 && newI < grid.length && newJ < grid[0].length && grid[newI][newJ] && grid[newI][newJ] != colorNumber) {
                colorIsland(newI, newJ);
            }
        }
    }
    
    function addLandCells() {
        for(let i = 0; i < grid.length; i++) {
            for(let j = 0; j < grid[0].length; j++) {
                if(grid[i][j]) {
                    landCells.push([i, j]);
                }
            }
        }
    }
    
    function findAnotherIsland() {
        for(let i = 0; i < grid.length; i++) {
            for(let j = 0; j < grid[0].length; j++) {
                if(grid[i][j] && grid[i][j] != colorNumber) {
                    return true;
                }
            }
        }
        return false;
    }
    
    addLandCells();
    
    if(landCells.length < 2) {
        return landCells.length;
    }
    
    colorIsland(landCells[0][0], landCells[0][1]);
    
    if(findAnotherIsland()) {
        return 0;
    }
    
    colorNumber++;
    
    for(let i = 0; i < landCells.length; i++) {
        grid[landCells[i][0]][landCells[i][1]] = 0;
        colorIsland(landCells[(i + 1) % landCells.length][0], landCells[(i + 1) % landCells.length][1]);
        if(findAnotherIsland()) {
            return 1;
        }
        grid[landCells[i][0]][landCells[i][1]] = colorNumber;
        colorNumber++;
    }
    
    return 2;
};
