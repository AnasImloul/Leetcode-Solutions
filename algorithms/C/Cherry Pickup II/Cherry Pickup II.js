/**
 * @param {number[][]} grid
 * @return {number}
 */
var cherryPickup = function(grid) {
    const numOfRow = grid.length
    const numOfCol = grid[0].length

    let memo = {} // must memorize the step result which already get, or you will get a TLE

    const dfs = (row, col1, col2) => {
        if (memo[`${row},${col1},${col2}`]) { // return the result once the location have already been calculated
            return memo[`${row},${col1},${col2}`]
        }

        let cherries = grid[row][col1] // Robot #1 location
        if (col1 !== col2) { // when both robots stay in the same cell, only one takes the cherries.
            cherries += grid[row][col2]
        }

        if (row === numOfRow - 1) return cherries // last row, no need to do more DFS

        let max = 0 // initial the max cherries with next row with min integer 0
		
		// all the possible locations with Robot #1 and Robot #2 should calculate, the max combination is 3*3=6
        for (let i = col1 - 1; i <= col1 + 1; i++) { // Robot #1 next step could be next row with current col-1, current col or current col+1
            for (let j = col2 - 1; j <= col2 + 1; j++) { // Robot #2 next step could be next row with current col-1, current col or current col+1
                if (i >= 0 && j >= 0 && i < numOfCol && j < numOfCol) { // Both robot next column should greater and equal than 0, less than numOfCol
                    max = Math.max(max, dfs(row + 1, i, j)) // save the max result with all the possible locations
                }
            }
        }
        memo[`${row},${col1},${col2}`] = max + cherries // save the result to memo
        return max + cherries // return the max cherries and the current position's cherries
    }
    return dfs(0, 0, numOfCol - 1) // from row 0, Robot #1 col1 = 0(top-left corner), Robot #2 col2 = numOfCol-1(top-right corner )
}
