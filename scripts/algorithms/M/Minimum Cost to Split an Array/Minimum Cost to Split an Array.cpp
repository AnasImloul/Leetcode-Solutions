// Runtime: 336 ms (Top 82.39%) | Memory: 133.00 MB (Top 87.32%)

class Solution {
public:
    int solve(int i,vector<int>&nums,int k,int n,vector<int>&dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        vector<int>mp(n,0);
        int cnt = 0;
        int ans = INT_MAX;
        for(int j = i;j < n;j++){
            mp[nums[j]]++;
            if(mp[nums[j]] == 2) cnt += 2;
            else if(mp[nums[j]] > 2) cnt++;
            ans = min(ans,solve(j+1,nums,k,n,dp)+cnt+k);
        }
        return dp[i] = ans;
    }
    int minCost(vector<int>& nums, int k) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,k,nums.size(),dp);
    }
};
