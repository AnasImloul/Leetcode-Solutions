class Solution {
public:
    
    int catalan (int n,vector<int> &dp)
    {
        if(n<=1)
            return 1;
        
        int ans =0;
        for(int i=0;i<n;i++)
        {
            ans+=catalan(i,dp)*catalan(n-1-i,dp);
        }
        
        return ans;
    }
    int numTrees(int n) {
        
        vector<int> dp(n+1,-1);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++)
        {
            int ans = 0;
            for(int j=0;j<i;j++)
            {
                ans += dp[j]*dp[i-1-j];
            }
            dp[i] = ans;
        }
        
        return dp[n];
        
        // return catalan(n,dp);
        
    }
};
