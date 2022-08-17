class Solution {
public:
    int mod = (int)(1e9 + 7);
    int dp[1001][1001] = {};
    
    int kInversePairs(int n, int k) {
        //base case
        if(k<=0) return k==0;
        
        if(dp[n][k]==0){
            dp[n][k] = 1;
            
            for(int i=0; i<n; i++){
                dp[n][k] = (dp[n][k] + kInversePairs(n-1,k-i))%mod;
            }
        }
        return dp[n][k]-1;
    }
};
