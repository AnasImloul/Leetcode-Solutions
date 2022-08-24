// Runtime: 76 ms (Top 85.71%) | Memory: 44.9 MB (Top 50.00%)
/**
 * @param {number} n
 * @return {number}
 */
var numOfWays = function(n) {
  const mod = Math.pow(10, 9) + 7;
  const dp212 = [6];
  const dp123 = [6];
  for (let i = 1; i < n; i++) {
    // two sides same
    dp212[i] = (dp212[i - 1] * (5 - 2) + dp123[i - 1] * (6 - 2 - 1 - 1)) % mod;
    // three different colors
    dp123[i] = (dp123[i - 1] * (5 - 1 - 1 - 1) + dp212[i - 1] * (6 - 2 - 2)) % mod;
  }
  return (dp212[n - 1] + dp123[n - 1]) % mod;
};