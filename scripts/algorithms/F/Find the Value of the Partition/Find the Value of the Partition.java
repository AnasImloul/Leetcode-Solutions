// Runtime: 20 ms (Top 50.3%) | Memory: 54.68 MB (Top 33.2%)

class Solution {
  public int findValueOfPartition(int[] nums) {
    int n = nums.length, ans = Integer.MAX_VALUE;
    Arrays.sort(nums);
    
    for (var i=0; i < n-1; i++)
      ans = Math.min(ans, nums[i+1] - nums[i]);
    
    return ans;
  }
}