/**
 * @param {number[]} nums
 * @return {number[]}
 */
var numberOfPairs = function(nums) {
  let pairs = 0;
  const s = new Set();
  for (const num of nums) {
    if (s.has(num)) {
      pairs += 1;
      s.delete(num);
    } else {
      s.add(num);
    }
  }
  return [pairs, nums.length - pairs * 2];
};