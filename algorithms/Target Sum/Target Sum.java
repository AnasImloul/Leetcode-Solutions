class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;
        for(int i:nums){
            sum += i;
        }
        if(target>sum || target<-sum || ((target+sum)&1)!=0) return 0;
        return subsetSum(nums,(target+sum)/2);
    }
    private int subsetSum(int[] nums,int target){
        int[][] dp = new int[nums.length+1][target+1];
        dp[0][0] = 1;
        
        for(int i=1;i<nums.length+1;i++){
            for(int j=0;j<target+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j] += dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else dp[i][j] += dp[i-1][j];
            }
        }
        return dp[nums.length][target];
    }
}
