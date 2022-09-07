// Runtime: 197 ms (Top 12.59%) | Memory: 48.9 MB (Top 29.63%)
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var shiftGrid = function(grid, k) {

    let m = grid.length
    let n = grid[0].length

    for (let r = 0; r < k; r++) {
        const newGrid = Array(m).fill("X").map(() => Array(n).fill("X"))
        for (let i = 0; i < m; i++) {
            for (let j = 1; j < n; j++) {
                newGrid[i][j] = grid[i][j-1]
            }
         }

        for (let i = 1; i < m; i++) {
            newGrid[i][0] = grid[i-1][n-1]
        }

        newGrid[0][0] = grid[m-1][n-1]

        //copy the new grid for the next iteration
        grid = newGrid
    }

    return grid

};