// Runtime: 54 ms (Top 87.13%) | Memory: 43.00 MB (Top 98.35%)

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var divideArray = function(nums) {
  return !nums.reduce((acc, cur) => (acc[cur]++, acc), new Uint16Array(501)).some(n => n % 2);
};
