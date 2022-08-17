class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n=size(nums);
        int ans=1;
        vector<vector<int>>  dp(n,vector<int>(1005,1));
        
        for(int i=1;i<n;i++) 
            for(int j=0;j<i;j++)
                ans=max(ans, dp[i][nums[i]-nums[j]+500]= 1+dp[j][nums[i]-nums[j] +500]);
             
        
        return ans;
        
    }
};
