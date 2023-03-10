class Solution 
{
public:
    int mod=1e9+7;
    int dp[1011][1011][3];
    int f(int i, int k, int n, int ended)
    {
        if(k==0) return 1;
        if(i==n) return 0;
        if(dp[i][k][ended]!=-1) return dp[i][k][ended];
        int ans=0;
        if(ended) ans=(ans+f(i+1,k,n,0)+f(i+1,k,n,1))%mod;
        else ans=(ans+f(i+1,k,n,0)+f(i,k-1,n,1))%mod;
        return dp[i][k][ended]=ans;
    }
    int numberOfSets(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return f(0,k,n,1);
    }
};