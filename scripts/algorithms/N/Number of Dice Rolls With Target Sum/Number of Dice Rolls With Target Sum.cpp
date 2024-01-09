// Runtime: 11 ms (Top 87.19%) | Memory: 6.50 MB (Top 92.03%)

class Solution {
public:
    #define MOD 1000000007
    int dp[32][1002];
    
    int solve(int d, int f, int target){
        if(d==0 && target==0) return 1;
        if(d<=0 || target<=0) return 0;
        if(dp[d][target] != -1) return dp[d][target];
     
        int sum=0;
        for(int i=1;i<=f;i++){
            sum = (sum % MOD + solve(d-1,f,target-i)%MOD)%MOD;
        }
        dp[d][target] = sum;
        return dp[d][target];
    }
    
    int numRollsToTarget(int d, int f, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(d,f,target);
    }
};
