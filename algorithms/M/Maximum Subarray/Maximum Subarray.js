/**
 * @param {number[]} nums
 * @return {number}
 */
 var maxSubArray = function(nums) {
   let max = Number.MIN_SAFE_INTEGER;
   let curr = 0;
   for (let i = 0; i < nums.length; i++) {
      if (curr < 0 && nums[i] > curr) {
          curr = 0;
      }
    curr += nums[i];
    max = Math.max(max, curr);
   }
  return max;
}; 
