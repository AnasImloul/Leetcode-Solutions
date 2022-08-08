class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
        }
        
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        vector<int>v;
        for(int i=0;i<=sum/2;i++){
            if(dp[n][i]==1)
                v.push_back(i);
        }
        int mn=INT_MAX;
        for(int i=0;i<v.size();i++){
            mn=min(mn,sum-2*v[i]);
        }
        return mn;
    }
};
