// Runtime: 101 ms (Top 95.88%) | Memory: 60 MB (Top 57.22%)
var validPartition = function(nums) {
  let n = nums.length, memo = Array(n).fill(-1);
  return dp(0);

  function dp(i) {
    if (i === n) return true;
    if (i === n - 1) return false;
    if (memo[i] !== -1) return memo[i];

    if (nums[i] === nums[i + 1] && dp(i + 2)) return memo[i] = true;
    if (i < n - 2) {
      if (!dp(i + 3)) return memo[i] = false;
      let hasThreeEqual = nums[i] === nums[i + 1] && nums[i + 1] === nums[i + 2];
      let hasThreeConsecutive = nums[i] + 1 === nums[i + 1] && nums[i + 1] + 1 === nums[i + 2];
      if (hasThreeEqual || hasThreeConsecutive) return memo[i] = true;
    }
    return memo[i] = false;
  }
};