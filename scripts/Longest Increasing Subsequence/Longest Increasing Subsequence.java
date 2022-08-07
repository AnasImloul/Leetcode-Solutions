class Solution {
    // memoization approach
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        
        // Inorder to use memoization, we need to store previous value
        // in the dp. so for that, create dp of length n+1 and n 
        // n+1 for previous indx and n for index of nums
        
        
        // in dp prev index is 0 till n 
        // in nums prev index is -1 till n-1
        
        int[][] dp = new int[n+1][n];
        
        // pass arguments according to nums i.e., prev=-1 and cur is 0;
        return LIS(-1, 0, nums, dp);
    }
    
    public int LIS(int prev, int cur, int[] nums, int[][] dp){
        // base case
        // cur shouldn't exeed nums length. 
        
        if(cur>=nums.length) return 0;
        
        // in dp, prev 0 --> n && cur 0 --> n-1
        // here with index -1 we cant store it in dp so, always use prev+1 in dp
        if(dp[prev+1][cur]!=0) return dp[prev+1][cur];
        
        // not take case
        // if we do not take case prev stays same and cur will increase by 1
        int len = LIS(prev, cur+1, nums, dp);
        
        // take case 
        // while checking condition in nums array, if prev is -1 means there is no
        // prev value,then just take the cur index value without checking condition
        
        if(prev==-1 || nums[prev]<nums[cur]){
            // when we take cur index, prev will change to cur index and 
            // cur will change to cur+1
            len = Math.max(len, 1+LIS(cur, cur+1, nums, dp));
        }
        
       // while storing in dp, we cant store prev in -1 index, so increament prev by 1
        dp[prev+1][cur] = len;
        
        // for the current recurrence function, we need to return len;
        return len;
    }
}

