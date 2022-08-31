// Runtime: 70 ms (Top 84.49%) | Memory: 41.9 MB (Top 82.23%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function(nums) {
  let first = -Infinity;
  let second = -Infinity;
  let ans = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > first) {
      second = first;
      first = nums[i];
      ans = i;
    } else if (nums[i] > second) {
      second = nums[i];
    }
  }
  return first >= second * 2 ? ans : -1;
};