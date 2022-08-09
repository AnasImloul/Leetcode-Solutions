/**
 * @param {number} n
 * @param {number} maxValue
 * @return {number}
 */
var idealArrays = function(n, maxValue) {
  const mod = 1e9 + 7;
  let cur = 0;
  let arr = Array(2).fill().map(() => Array(maxValue).fill(1));
  for (let l = 2; l <= n; l++) {
    const prev = arr[cur];
    const next = arr[1-cur];
    for (let s = 1; s <= maxValue; s++) {
      let res = 0;
      for (let m = 1; m * s <= maxValue; m++) {
        res = (res + prev[m * s - 1]) % mod;
      }
      next[s-1] = res;
    }
    cur = 1 - cur;
  }
  const res = arr[cur].reduce((a, b) => (a + b) % mod, 0);
  return res;
};
