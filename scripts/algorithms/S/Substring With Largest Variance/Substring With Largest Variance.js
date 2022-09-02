// Runtime: 1461 ms (Top 30.30%) | Memory: 44.6 MB (Top 59.39%)
var largestVariance = function(s) {
  let chars = new Set(s.split("")), maxDiff = 0;
  for (let l of chars) {
    for (let r of chars) {
      if (l === r) continue;
      let lCount = 0, rCount = 0, hasRight = false;
      for (let char of s) {
        lCount += char === l ? 1 : 0;
        rCount += char === r ? 1 : 0;
        if (rCount > 0 && lCount > rCount) { // has both characters and positive difference
          maxDiff = Math.max(maxDiff, lCount - rCount);
        }
        if (lCount > rCount && hasRight) { // has positive difference and a previous "right" character we can add to the start
          maxDiff = Math.max(maxDiff, lCount - rCount - 1);
        }
        if (lCount < rCount) {
          lCount = 0, rCount = 0;
          hasRight = true;
        }
      }
    }
  }
  return maxDiff;
};