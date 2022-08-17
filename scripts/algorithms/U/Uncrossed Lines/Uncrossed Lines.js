/** https://leetcode.com/problems/uncrossed-lines/
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxUncrossedLines = function(nums1, nums2) {
  // Array to hold the combination of connected numbers
  let dp = [];
  
  // We look up the connected numbers with matrix
  for (let i=0;i< nums1.length;i++){
    for (let j=0;j< nums2.length;j++){
      if (nums1[i]===nums2[j]){
        dp.push([i,j]);
      }
    }
  }
  
  // Only 0 or 1 connected numbers found, return
  if(dp.length <=1){
    return dp.length;
  }
  
  // Array to count how many connected numbers in the matrix without crossing
  let count=Array(dp.length).fill(1);
  let out = count[0];
  
  // Count from the last connected numbers, for each connected number, count how many other connected numbers in front of it that will not crossed with current
  for (let i=dp.length-2;i>=0;i--){
    for (let j=i+1;j<dp.length;j++){
      if (dp[i][0] < dp[j][0]&&
          dp[i][1] < dp[j][1]){
            count[i] = Math.max(count[i],count[j]+1);
            out = Math.max(out, count[i]);
      }
    }
  }
  
  return out;
};
