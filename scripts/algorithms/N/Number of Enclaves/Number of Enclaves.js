// Runtime: 170 ms (Top 26.04%) | Memory: 54.3 MB (Top 16.57%)
/**
 * @param {number[][]} grid
 * @return {number}
 */
var numEnclaves = function(grid) {

    let count = 0, rowLength = grid.length, colLength = grid[0].length

    const updateBoundaryLand = (row,col) => {
        if(grid?.[row]?.[col]){
            grid[row][col] = 0
            updateBoundaryLand(row + 1,col)
            updateBoundaryLand(row - 1,col)
            updateBoundaryLand(row,col + 1)
            updateBoundaryLand(row,col - 1)

        }
    }

    for(let i=0;i<rowLength;i++){
        if(grid[i][0] || grid[i][colLength-1]){
            updateBoundaryLand(i,0)
            updateBoundaryLand(i,colLength-1)
        }
    }

    for(let j=0;j<colLength;j++){
        if(grid[0][j] || grid[rowLength-1][j]){
            updateBoundaryLand(0,j)
            updateBoundaryLand(rowLength-1,j)
        }
    }

    for(let i=0;i<rowLength;i++){
        for(let j=0;j<colLength;j++){
            if(grid[i][j]) count++
        }
    }

    return count

};