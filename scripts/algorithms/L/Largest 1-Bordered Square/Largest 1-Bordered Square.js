// Runtime: 166 ms (Top 33.33%) | Memory: 44.7 MB (Top 55.56%)
var largest1BorderedSquare = function(grid) {
  let m = grid.length, n = grid[0].length;
  let top = Array(m).fill(0).map(() => Array(n).fill(0));
  let left = Array(m).fill(0).map(() => Array(n).fill(0));
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === 1) {
        left[i][j] = j > 0 ? left[i][j - 1] + 1 : 1;
        top[i][j] = i > 0 ? top[i - 1][j] + 1 : 1;
      }
    }
  }

  let ans = 0;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      let size = Math.min(top[i][j], left[i][j]);
      for (let k = size; k > 0; k--) {
        let bottomLeftTop = top[i][j - k + 1];
        let topRightLeft = left[i - k + 1][j];
        if (bottomLeftTop >= k && topRightLeft >= k) {
          ans = Math.max(ans, k * k);
          break;
        }
      }
    }
  }
  return ans;
};