var findBall = function(grid) {
    let m = grid.length,
        n = grid[0].length,
        ans = []
    for (let start = 0; start < n; start++) {     // Iterate through the different starting conditions
        let j = start
        for (let i = 0; i < m; i++) {             // Then iterate downward from grid[i][j]
            let dir = grid[i][j]                  // Compare the direction of the current cell to the direction
            if (dir === grid[i][j+dir]) j += dir  //   of the cell on the slant side and move that way if matched
            else i = m, j = -1                    // Otherwise jump to the loop's end and set j to the fail value
        }
        ans[start] = j                            // Update the answer
    }
    return ans                                    // Return the completed answer
};
