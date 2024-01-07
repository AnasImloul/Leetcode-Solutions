// Runtime: 72 ms (Top 94.85%) | Memory: 47.70 MB (Top 62.89%)

var updateBoard = function(board, click) {
  const rows = board.length;
  const cols = board[0].length;
  dfs(click[0], click[1]);
  return board;

  function dfs(i, j) {
    if (!board[i][j]) return;
    if (board[i][j] === 'M') {
      board[i][j] = 'X';
      return;
    }
    if (board[i][j] !== 'E') return;

    const mines = checkForMine(i, j); // Check for mines
	
    if (mines) {
      board[i][j] = mines.toString();
      return;
    } else {
      // If we haven't got mines, check another cells
      board[i][j] = 'B';
      for (let x = Math.max(i - 1, 0); x < Math.min(i + 2, rows); x++) {
        for (let y = Math.max(j - 1, 0); y < Math.min(j + 2, cols); y++) {
          dfs(x, y);
        }
      }
    }
  }

  function checkForMine(x, y) {
    let mines = 0;
    for (let i = Math.max(x - 1, 0); i < Math.min(x + 2, rows); i++) {
      for (let j = Math.max(y - 1, 0); j < Math.min(y + 2, cols); j++) {
        if (board[i][j] === 'M') mines++;
      }
    }
    return mines;
  }
}
