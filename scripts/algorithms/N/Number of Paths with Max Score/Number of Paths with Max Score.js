// Runtime: 273 ms (Top 14.29%) | Memory: 62 MB (Top 14.29%)
var pathsWithMaxScore = function(board) {
  let n = board.length, dp = Array(n + 1).fill(0).map(() => Array(n + 1).fill(0).map(() => [-Infinity, 0]));
  let mod = 10 ** 9 + 7;
  dp[n - 1][n - 1] = [0, 1]; // [max score, number of paths]

  for (let i = n - 1; i >= 0; i--) {
    for (let j = n - 1; j >= 0; j--) {
      if (board[i][j] === 'X' || board[i][j] === 'S') continue;

      let paths = [dp[i][j + 1], dp[i + 1][j + 1], dp[i + 1][j]];
      for (let [maxScore, numPaths] of paths) {
        if (dp[i][j][0] < maxScore) {
          dp[i][j] = [maxScore, numPaths];
        } else if (dp[i][j][0] === maxScore) {
          dp[i][j][1] = (dp[i][j][1] + numPaths) % mod;
        }
      }
      let score = board[i][j] === 'E' ? 0 : Number(board[i][j]);
      dp[i][j][0] += score;
    }
  }
  return dp[0][0][1] === 0 ? [0, 0] : dp[0][0];
};