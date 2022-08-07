class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i=0; i<nums.length; i++){
            sum = sum+nums[i];
        }
       
        if(sum%2 !=0){
            return false;
        }
        int[][] dp = new int[nums.length+1][sum];
        for(int i=0; i<dp.length; i++){
            Arrays.fill(dp[i],-1);
        }
       
        return helper(nums,sum/2,0,dp)>= 1? true : false;
    }
    public int helper(int[] nums, int sum, int i, int[][] dp){
        if(i==nums.length && sum==0){
            return 1;
        }
        if(i==nums.length){
            return 0;
        }
        if(sum < 0){
            return 0;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        if(sum<nums[i]){
           return dp[i][sum] = helper(nums,sum,i+1,dp);
        }
        int a = helper(nums,sum-nums[i],i+1,dp); //Take the value
        int b = helper(nums,sum,i+1,dp); //Not take the value
        if(a==1 || b==1){   // if any of the options is returning true then whole answer would be true
                return dp[i][sum]=1;
        }else{
                return dp[i][sum]=0;
        }
    }
}
