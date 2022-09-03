// Runtime: 612 ms (Top 71.43%) | Memory: 69.4 MB (Top 100.00%)
var largestComponentSize = function(nums) {
  const rootByFactor = new Map();
  const parents = new Array(nums.length);

  function addFactor(i, factor) {
    if (rootByFactor.has(factor)) {
      let r = rootByFactor.get(factor);
      while (parents[i] != i) i = parents[i];
      while (parents[r] != r) r = parents[r];
      parents[i] = r;
    }
    rootByFactor.set(factor, parents[i]);
  }

  for (const [i, num] of nums.entries()) {
    parents[i] = i;
    addFactor(i, num);
    for (let factor = 2; factor * factor <= num; ++factor) {
      if (num % factor == 0) {
        addFactor(i, factor);
        addFactor(i, num / factor);
      }
    }
  }

  let largest = 0;
  const sums = new Array(nums.length).fill(0);
  for (let r of parents) {
    while (parents[r] != r) r = parents[r];
    largest = Math.max(largest, ++sums[r]);
  }
  return largest;
};