/**
 * @param {number[]} nums
 * @return {number}
 */
var zeroFilledSubarray = function(nums) {
  let numOfSubarray = 0
    
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === 0) {
      let j = i
      while (nums[j] === 0 && j < nums.length) {
        j++
      }
      
      numOfSubarray += (j - i + 1) * (j - i) / 2
      i = j
    }
  }
  
  return numOfSubarray
};
