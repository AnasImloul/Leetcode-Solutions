// Runtime: 109 ms (Top 19.53%) | Memory: 42.4 MB (Top 13.28%)

var check = function(nums) {
  let decreased = false
  for (let i = 1; i < nums.length; i += 1) {
    if (nums[i] < nums[i - 1]) {
      if (decreased) {
        return false
      }
      decreased = true
    }
  }
  return decreased ? nums[0] >= nums[nums.length - 1] : true
};