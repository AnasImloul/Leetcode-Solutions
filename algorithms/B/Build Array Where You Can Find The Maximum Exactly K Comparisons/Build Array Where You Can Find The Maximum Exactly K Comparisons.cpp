class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if(m<k)return 0;
        int dp[2][m+1][k+1],mod=1e9+7;
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=m;++j)
            dp[0][j][1]=j;
        for(int i=1;i<n;++i)
            for(int j=1;j<=m;++j)
                for(int l=1;l<=min(i+1,min(j,k));++l)
                    dp[i&1][j][l]=(dp[i&1][j-1][l]+(long)(dp[(i-1)&1][j][l]-dp[(i-1)&1][j-1][l])*j+dp[(i-1)&1][j-1][l-1])%mod;
        return (dp[(n-1)&1][m][k]+mod)%mod;
    }
};
