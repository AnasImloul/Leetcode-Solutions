// Runtime: 267 ms (Top 66.25%) | Memory: 55.4 MB (Top 55.00%)
var countPaths = function(grid) {
  let mod = Math.pow(10, 9) + 7;
  let result = 0;
  let rows = grid.length, columns = grid[0].length;
  let dp = Array(rows).fill(null).map(_ => Array(columns).fill(0));

  const dfs = (r, c, preVal)=> {
    if (r < 0 || r == rows || c < 0 || c == columns || grid[r][c] <= preVal) return 0
    if (dp[r][c]) return dp[r][c]
    return dp[r][c] = (1 + dfs(r + 1, c, grid[r][c]) +
                       dfs(r - 1, c, grid[r][c]) +
                       dfs(r , c + 1, grid[r][c]) +
                       dfs(r , c - 1, grid[r][c])) % mod;
  }
   for(let i = 0; i < rows; i++) {
    for(let j = 0; j < columns; j++) {
      result += dfs(i, j, -1) % mod;
    }
  }

  return result % mod;
};