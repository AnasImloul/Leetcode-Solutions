// Runtime: 193 ms (Top 7.04%) | Memory: 48.6 MB (Top 15.49%)
var mctFromLeafValues = function(arr) {
  const dp = [];

  for (let i = 0; i < arr.length; i++) {
    dp[i] = [];
  }

  return treeBuilder(0, arr.length - 1);

  function treeBuilder(start, end) {

    if (start == end) {
      return 0;
    }

    if (dp[start][end]) {
      return dp[start][end];
    }

    let min = Number.MAX_VALUE;

    for (let i = start; i < end; i++) {
      const left = treeBuilder(start, i);
      const right = treeBuilder(i + 1, end);

      const maxLeft = Math.max(...arr.slice(start, i + 1));
      const maxRight = Math.max(...arr.slice(i + 1, end + 1));

      const rootVal = maxLeft * maxRight;

      min = Math.min(min, rootVal + left + right);

    }

    dp[start][end] = min;
    return min;
  }
};