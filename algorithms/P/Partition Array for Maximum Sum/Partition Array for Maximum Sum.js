/** https://leetcode.com/problems/partition-array-for-maximum-sum/
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var maxSumAfterPartitioning = function(arr, k) {
  // Array to hold max value for each integer in `arr`
  let dp = Array(arr.length).fill(0);
  dp[0] = arr[0];
  
  // Calculate max value for each integer
  for (let i = 1; i < arr.length; i++) {
    // The `maxK` is largest number from `i` to `i - k - 1`
    let maxK = 0;
    
    // The `maxVal` is for holding max value to be added to `dp[i]`
    let maxVal = 0;
    
    // Loop through `i` to `i - k - 1`
    for (let j = 1; j <= k; j++) {
      // Get max number
      maxK = Math.max(maxK, arr[i - (j - 1)]);
      
      // Calculate `maxVal`, if current `i` is smaller than `k`, we don't need to continue
      if (i < j) {
        maxVal = Math.max(maxVal, maxK * j);
        break;
      }
      
      maxVal = Math.max(maxVal, dp[i - j] + (maxK * j));
    }
    
    // Store `maxVal`
    dp[i] = maxVal;
  }
  
  return dp[dp.length - 1];
};
