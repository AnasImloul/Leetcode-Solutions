// Runtime: 158 ms (Top 24.60%) | Memory: 46.4 MB (Top 75.40%)
var snakesAndLadders = function(board) {
    let n = board.length;
  let seen = new Set();
  let queue = [[1, 0]];

  while (queue.length) {
    let [label, step] = queue.shift();
    //console.log(label, step);
    let [r, c] = labelToPosition(label, n);
    //console.log(r, c, n);
    if (board[r][c] !== -1) {
      label = board[r][c];
    }
    if (label == n * n) {
      return step;
    }
    for (let x = 1; x < 7; x++) {
      let nextLabel = label + x;
      if (nextLabel <= n * n && !seen.has(nextLabel)) {
        seen.add(nextLabel);
        queue.push([nextLabel, step + 1]);
      }
    }
  }
  return -1;
};

const labelToPosition = (label, n) => {
  let row = Math.floor((label - 1) / n);
  let col = (label - 1) % n;
  //console.log("label", row, col);
  if (row % 2 === 0) {
    return [n - 1 - row, col];
  } else {
    return [n - 1 - row, n - 1 - col];
  }
};