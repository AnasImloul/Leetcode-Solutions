// Runtime: 27 ms (Top 12.25%) | Memory: 82.9 MB (Top 64.19%)
// Time O(n)
// Space O(n)
class Solution {
    public boolean validPartition(int[] nums) {
        boolean[] dp = new boolean[nums.length+1];
        dp[0]=true; // base case
        for (int i = 2; i <= nums.length; i++){
            dp[i]|= nums[i-1]==nums[i-2] && dp[i-2]; // cond 1
            dp[i]|= i>2 && nums[i-1] == nums[i-2] && nums[i-2] == nums[i-3] && dp[i-3]; // cond 2
            dp[i]|= i>2 && nums[i-1]-nums[i-2]==1 && nums[i-2]-nums[i-3]==1 && dp[i-3]; // cond 3
        }
        return dp[nums.length];
    }
}