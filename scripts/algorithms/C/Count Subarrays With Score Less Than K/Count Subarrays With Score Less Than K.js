// Runtime: 81 ms (Top 78.57%) | Memory: 53.40 MB (Top 28.57%)

var countSubarrays = function(nums, k) {
  let curentRunningSum = 0, result = 0, windowEnd = 0, windowStart = 0;
  while (windowEnd < nums.length) {
    curentRunningSum += nums[windowEnd];
    while (curentRunningSum * (windowEnd - windowStart + 1) >= k)  curentRunningSum -= nums[windowStart++];
    result += windowEnd - windowStart + 1;
    windowEnd++;
  }
  return result; 
};
