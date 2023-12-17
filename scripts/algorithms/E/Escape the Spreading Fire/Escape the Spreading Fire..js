// Runtime: 257 ms (Top 50.0%) | Memory: 63.30 MB (Top 50.0%)

var maximumMinutes = function(grid) {
  let fireSpread = getFireSpreadTime(grid);
  let low = 0, high = 10 ** 9;
  while (low < high) {
    let mid = Math.ceil((low + high) / 2);
    if (canReachSafehouse(grid, fireSpread, mid)) low = mid;
    else high = mid - 1;
  }
  return canReachSafehouse(grid, fireSpread, low) ? low : -1;
};

function canReachSafehouse(originalGrid, fireSpread, timeToWait) {
  const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  let grid = originalGrid.map((row) => [...row]);
  let m = grid.length, n = grid[0].length;
  let queue = [[0, 0]], time = timeToWait;
  while (queue.length) {
    for (let i = queue.length; i > 0; i--) {
      let [row, col] = queue.shift();
      if (row === m - 1 && col === n - 1) {
        return true;
      }
      for (let [x, y] of directions) {
        let newX = row + x, newY = col + y;
        if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] !== 0) continue; // out of bounds or cell is not grass
        let isTarget = newX === m - 1 && newY === n - 1;
        if ((isTarget && time + 1 <= fireSpread[newX][newY]) || time + 1 < fireSpread[newX][newY]) { // only visit if fire will not spread to new cell at the next minute
          grid[newX][newY] = 1;
          queue.push([newX, newY]);
        }
      }
    }
    time++;
  }
  return false;
}

function getFireSpreadTime(originalGrid) {
  const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  let grid = originalGrid.map((row) => [...row]);
  let m = grid.length, n = grid[0].length;
  let queue = [];
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === 1) {
        queue.push([i, j]);
      }
    }
  }
  
  let time = 0, fireSpread = Array(m).fill(0).map(() => Array(n).fill(Infinity));
  while (queue.length) {
    for (let i = queue.length; i > 0; i--) {
      let [row, col] = queue.shift();
      fireSpread[row][col] = time;
      for (let [x, y] of directions) {
        let newX = row + x, newY = col + y;
        if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] !== 0) continue; // out of bounds or cell is not grass
        grid[newX][newY] = 1;
        queue.push([newX, newY]);
      }
    }
    time++;
  }
  return fireSpread;
}
