class Solution {
public:
    int MOD = 1e9+7;
    int sumDyp(int n, int k, vector<vector<int>> &dp, vector<vector<int>> &sumDp)
    {
        if(n < 2)
            return 0;
        
        if(sumDp[n][k] != -1)
            return sumDp[n][k];
        
        sumDp[n][k] = ((sumDyp(n-1, k, dp, sumDp)%MOD) + (dyp(n, k, dp, sumDp)%MOD))%MOD;
        return sumDp[n][k];
    }
        
    int dyp(int n, int k, vector<vector<int>> &dp, vector<vector<int>> &sumDp)
    {
        if(n < 2)
            return 0;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        if(k == 1)
        {
            dp[n][k] = ((((n-1)%MOD) * (n%MOD))%MOD)/2;
            return dp[n][k];
        }
        
        
        int ans1 = dyp(n-1, k, dp, sumDp);
        int ans2 = sumDyp(n-1, k-1, dp, sumDp);
        
        int ans = ((ans1%MOD) + (ans2%MOD))%MOD;
        dp[n][k] = ans;
        return ans;
    }
    
    int numberOfSets(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        vector<vector<int>> sumDp(n+1, vector<int>(k+1, -1));
        return dyp(n, k, dp, sumDp);
    }
};
