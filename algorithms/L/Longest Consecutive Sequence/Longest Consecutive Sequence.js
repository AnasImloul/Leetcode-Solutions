/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
  if(nums.length === 1){
    return 1
  }
  if(nums.length === 0){
    return 0
  }
  nums.sort((a, b) => a - b)
  let result = 1
  let streak = 1
  let i = 0
  while(i < nums.length - 1){
    if(nums[i] == nums[i + 1]) {
      i++ 
      continue
    }
    if(nums[i] == nums[i + 1] - 1){
      streak++
       if(streak > result){
         result = streak
       }
    } else {
      streak = 1
    }
    i++
  }
  return result
};
