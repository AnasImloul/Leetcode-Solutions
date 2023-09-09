// Runtime: 46 ms (Top 98.6%) | Memory: 44.86 MB (Top 73.9%)

/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findColumnWidth = function(grid) {
    const m = grid.length
    const n = grid[0].length
    const ans = []
    for (let j = 0; j < n; j++) {
      let len = 1
      for (let i = 0; i < m; i++) {
        len = Math.max(len, grid[i][j].toString().length)
      }
      ans.push(len)
    }
    return ans
};