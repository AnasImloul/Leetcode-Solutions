class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j]<nums[i]){
                    ans = max(dp[j]+1, ans);
                }
                
            }
            dp[i]=ans;
            ans=1;
        }
    
        int res=0;
        for(int i=0;i<n;i++){
            res = max(res, dp[i]);
        }

        return res;
        
    }
};
