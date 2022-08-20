// Runtime: 247 ms (Top 9.09%) | Memory: 45 MB (Top 68.18%)

var stoneGameII = function(piles) {
  const length = piles.length;
  const dp = [...Array(length + 1).fill(null)].map((_) =>
    Array(length + 1).fill(0)
  );
  const sufsum = new Array(length + 1).fill(0);
  for (let i = length - 1; i >= 0; i--) {
    sufsum[i] = sufsum[i + 1] + piles[i];
  }
  for (let i = 0; i <= length; i++) {
    dp[i][length] = sufsum[i];
  }
  for (let i = length - 1; i >= 0; i--) {
    for (let j = length - 1; j >= 1; j--) {
      for (let X = 1; X <= 2 * j && i + X <= length; X++) {
        dp[i][j] = Math.max(dp[i][j], sufsum[i] - dp[i + X][Math.max(j, X)]);
      }
    }
  }
  return dp[0][1];
};