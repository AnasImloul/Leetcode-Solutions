// Runtime: 499 ms (Top 76.47%) | Memory: 108.2 MB (Top 70.59%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function(nums) {
  let dp = new Array(nums.length);
  for(let i = 0; i < nums.length; i++) {
    dp[i] = new Map();
  }
  let ans = 0;
  for(let j = 1; j < nums.length; j++) {
    for(let i = 0; i < j; i++) {
      let commonDifference = nums[j] - nums[i];
      if ((commonDifference > (Math.pow(2, 31) - 1)) || commonDifference < (-Math.pow(2, 31))) {
        continue;
      }
      let apsEndingAtI = dp[i].get(commonDifference) || 0
      let apsEndingAtJ = dp[j].get(commonDifference) || 0

      dp[j].set(commonDifference, (apsEndingAtI + apsEndingAtJ + 1));
      ans += apsEndingAtI;
    }
  }
  return ans;
};