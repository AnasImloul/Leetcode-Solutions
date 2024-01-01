// Runtime: 93 ms (Top 9.09%) | Memory: 48.40 MB (Top 63.64%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var xorBeauty = function(nums) {
      let result = 0;
      let len = nums.length;
      for (let m = 0 ; m < len ; ++m) {
        result = result ^ nums[m];
      }
        return result;
};
