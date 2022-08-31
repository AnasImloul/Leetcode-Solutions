// Runtime: 171 ms (Top 98.16%) | Memory: 8.2 MB (Top 63.13%)
class Solution {
public:
    int dp[205][205];
    #define maxi pow(10,8)
    #define ll long long
    int dfs(vector<int>& nums, int idx, int k)
    {
        int n = nums.size();
        if(idx==n) return 0;
        if(k<0) return maxi;
        if(dp[idx][k]!=-1) return dp[idx][k];
        ll sum = 0, mx = 0, ans = maxi;
        for(int i=idx; i<n; i++)
        {
            sum += nums[i];
            mx = max(mx,(ll)nums[i]);
            ans = min(ans,mx*(i-idx+1)-sum + dfs(nums,i+1,k-1));
        }
        return dp[idx][k] = ans;
    }

    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,0,k);
    }
};