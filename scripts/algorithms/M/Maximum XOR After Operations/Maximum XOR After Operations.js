/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumXOR = function(nums) {
  return nums.reduce((acc, cur) => acc |= cur, 0);
};
