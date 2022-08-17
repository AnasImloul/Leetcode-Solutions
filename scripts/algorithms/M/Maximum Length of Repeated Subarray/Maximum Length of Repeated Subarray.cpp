class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        
        int ans=0;
        for(int i=1;i<(nums1.size()+1);i++)
        {
            for(int j=1;j<(nums2.size()+1);j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
};
