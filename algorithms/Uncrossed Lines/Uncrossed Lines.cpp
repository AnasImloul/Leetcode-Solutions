class Solution {
public:
    int solve(int n1,int n2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp)
    {
        if(n1<0 || n2<0)
            return 0;
        
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];
        
        if(nums1[n1]==nums2[n2])
            return dp[n1][n2]=1+solve(n1-1,n2-1,nums1,nums2,dp);
        
        return dp[n1][n2]=max(solve(n1-1,n2,nums1,nums2,dp),solve(n1,n2-1,nums1,nums2,dp));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        return solve(n1-1,n2-1,nums1,nums2,dp);
    }
};
