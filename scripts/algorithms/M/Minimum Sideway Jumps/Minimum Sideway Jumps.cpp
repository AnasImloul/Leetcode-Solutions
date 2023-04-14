class Solution {
public:
    int func(int i,int l,vector<int>&obstacles,vector<vector<int>>&dp){
        if(i==obstacles.size()-2){
            if(obstacles[i+1]==l)return 1;
            return 0;
        }

        if(dp[i][l]!=-1)return dp[i][l];

        if(obstacles[i+1]!=l){
            return dp[i][l] = func(i+1,l,obstacles,dp);
        }

    
        int b=INT_MAX;
        for(int j=1;j<=3;j++){
            if(l==j)continue;
            if(obstacles[i]==j)continue;
            b=min(b,1+func(i,j,obstacles,dp));
        }
    

        return dp[i][l] = b;
    }

    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return func(0,2,obstacles,dp);
    }
};