const minOperations = function (targets, arr) {
  const map = {};
  const n = targets.length;
  const m = arr.length;
  targets.forEach((target, i) => (map[target] = i));

//map elements in arr to index found in targets array
  const arrIs = arr.map(el => {
    if (el in map) {
      return map[el];
    } else {
      return -1;
    }
  });

//create a LIS table dp whose length is the longest increasing subsequence
  const dp = [];

  for (let i = 0; i < m; i++) {
    const curr = arrIs[i];
    if (curr === -1) continue;
    if (!dp.length || curr > dp[dp.length - 1]) {
      dp.push(curr);
    } else if (curr < dp[0]) {
      dp[0] = curr;
    } else {
      let l = 0;
      let r = dp.length;
      while (l < r) {
        const mid = Math.floor((l + r) / 2);
        if (arrIs[i] <= dp[mid]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      dp[r] = curr;
    }
  }
  return n-dp.length;
};