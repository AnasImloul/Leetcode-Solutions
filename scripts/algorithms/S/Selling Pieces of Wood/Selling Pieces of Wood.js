// Runtime: 908 ms (Top 24.08%) | Memory: 63.8 MB (Top 18.52%)
var sellingWood = function(m, n, prices) {
  let price = Array(n + 1).fill(0).map(() => Array(m + 1).fill(0));
  for (let [height, width, woodPrice] of prices) {
    price[width][height] = woodPrice;
  }
  let memo = Array(n + 1).fill(0).map(() => Array(m + 1).fill(-1));
  return dfs(n, m);

  function dfs(width, height) {
    if (width === 0 || height === 0) return 0;
    if (memo[width][height] !== -1) return memo[width][height];

    let ans = price[width][height];
    for (let h = 1; h <= Math.floor(height / 2); h++) {
      ans = Math.max(ans, dfs(width, h) + dfs(width, height - h));
    }
    for (let w = 1; w <= Math.floor(width / 2); w++) {
      ans = Math.max(ans, dfs(w, height) + dfs(width - w, height));
    }
    return memo[width][height] = ans;
  }
};