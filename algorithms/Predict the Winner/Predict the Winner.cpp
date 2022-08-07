class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(3,INT_MAX)));
        int t=fun(dp,nums,0,nums.size()-1,1);
        return t>=0;
    }
    int fun(vector<vector<vector<int>>>& dp,vector<int>& v,int i,int j,int t)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j][t+1]!=INT_MAX)
            return dp[i][j][t+1];
        
        if(t>0)
            return dp[i][j][t+1]=max(v[i]*t+fun(dp,v,i+1,j,-1),v[j]*t+fun(dp,v,i,j-1,-1));
        else
            return dp[i][j][t+1]=min(v[i]*t+fun(dp,v,i+1,j,1),v[j]*t+fun(dp,v,i,j-1,1));
    }
};
