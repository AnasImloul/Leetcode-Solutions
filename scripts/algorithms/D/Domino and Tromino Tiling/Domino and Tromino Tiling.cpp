class Solution {
public:
    int numTilings(int n) {
        long dp[n+1];
        dp[0]=1;
        for(int i=1; i<=n; i++){
            if(i<3)
                dp[i]=i;
            else
                dp[i] = (dp[i-1]*2+dp[i-3])%1000000007;
        }
        return (int)dp[n];
    }
};