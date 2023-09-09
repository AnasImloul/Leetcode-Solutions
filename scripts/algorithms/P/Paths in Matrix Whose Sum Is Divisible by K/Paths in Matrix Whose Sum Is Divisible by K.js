// Runtime: 601 ms (Top 20.0%) | Memory: 160.73 MB (Top 20.0%)

var numberOfPaths = function(grid, k) {
  let m = grid.length, n = grid[0].length, MOD = 10 ** 9 + 7;
  let memo = Array(m).fill(0).map(() => Array(n).fill(0).map(() => Array(k).fill(-1)));
  return dfs(0, 0, grid[0][0] % k);

  function dfs(i, j, sumMod) {
    if (i === m - 1 && j === n - 1) return sumMod === 0 ? 1 : 0;
    if (memo[i][j][sumMod] !== -1) return memo[i][j][sumMod];

    let paths = [[i + 1, j], [i, j + 1]], ways = 0;
    for (let [x, y] of paths) {
      if (x < 0 || x >= m || y < 0 || y >= n) continue;
      ways = (ways + dfs(x, y, (sumMod + grid[x][y]) % k)) % MOD;
    }
    return memo[i][j][sumMod] = ways;
  }
};