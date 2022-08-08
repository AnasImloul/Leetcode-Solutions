 class Solution {
public:
    int ans=0;
    int f(vector<int>&prices,int i,int buy,vector<vector<int>>&dp,int fee){
        if(i==prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int take=0;
        if(buy){
            take=max(-prices[i]+f(prices,i+1,0,dp,fee),f(prices,i+1,1,dp,fee));
        }
        else{
            take=max(prices[i]+f(prices,i+1,1,dp,fee)-fee,f(prices,i+1,0,dp,fee));
        }return dp[i][buy]=take;
    }
    int maxProfit(vector<int>& prices, int fee) {
         vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(prices,0,1,dp,fee);
    }
};
