/**
 * @param {number[]} nums
 * @return {boolean}
 */
var divideArray = function(nums) {
  return !nums.reduce((acc, cur) => (acc[cur]++, acc), new Uint16Array(501)).some(n => n % 2);
};
