class Solution {

// dp[idx][k]=minimum wasted space in between [idx....n-1] if we resize the region k times 

    int INF=200 *(int)1e6; // according to constarints { 1 <= nums.length <= 200 , 1 <= nums[i] <= 106 }
    public int minSpaceWastedKResizing(int[] nums, int k) {
        
        int dp[][]=new int[nums.length+1][k+1];
        memeset(dp, -1);
        return f(dp, 0, k, nums);
        
    }
    
    int f(int dp[][], int idx, int k, int nums[])
    {
        if(idx==nums.length)
            return 0;
        if(k==-1)
            return INF;
        
        if(dp[idx][k] != -1)
            return dp[idx][k];
        
        int ans=INF, max=nums[idx], sum=0;
        
        for(int j=idx; j<nums.length; ++j)
        {
            max=Math.max(max, nums[j]);
            sum+=nums[j];
        /**    
             total waste in between [idx...j] would be
             summation of (max-nums[idx] + max-nums[idx+1]....max-nums[j])
             length would be (j-idx+1) and these summation would be
             (j-idx+1) * max upto j - (nums[idx]+nums[idx+1]....+nums[j]
 
            as i have made one partition in between [idx...j] then remainig (k-1) partitions would be in between [j+1....n-1]
            and that value will be calculated by the recursion and we have to take the minimum answer from all these combinations 
            and to avoid tle we are using memozization
        **/
            int total_waste_upto_j=(j-idx+1)*max - sum;
            ans=Math.min(ans,  total_waste_upto_j + f(dp, j+1, k-1, nums));
            
        }
        
        return dp[idx][k]=ans;
    }
    
    void memeset(int dp[][], int val)
    {
        for(int x[]: dp)
            Arrays.fill(x, val);
    }
}

// tc: O(n^2 * k) there will be total (n*k) states  because for each k there are n possibilities and for each n there will be loop running n times
// so in total there will be O(n^2 * k) [because k<n]
// sc: O(n*k)
