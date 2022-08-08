/**
 * @param {number[]} nums
 * @return {number[]}
 */
var minSubsequence = function(nums) {
  const target = nums.reduce((a, b) => a + b) / 2;
  nums.sort((a, b) => b - a);
  let i = 0, sum = 0;
  while (sum <= target) {
    sum += nums[i++];
  }
  return nums.slice(0, i);
};
