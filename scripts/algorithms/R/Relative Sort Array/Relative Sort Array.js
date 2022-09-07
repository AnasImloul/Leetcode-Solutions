// Runtime: 92 ms (Top 51.55%) | Memory: 42.4 MB (Top 64.95%)
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
  const indices = new Map();
  arr2.forEach(indices.set, indices);

  return arr1.sort((a, b) => {
    if (indices.has(a)) {
      return indices.has(b) ? indices.get(a) - indices.get(b) : -1;
    }
    if (indices.has(b)) {
      return 1;
    }
    return a - b;
  });
};