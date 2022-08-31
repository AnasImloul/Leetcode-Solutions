// Runtime: 18 ms (Top 56.69%) | Memory: 13.1 MB (Top 35.45%)
class Solution {
public:
    int solve(int ind, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(k==0 || ind==prices.size()) return 0;
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        if(buy){
            return dp[ind][buy][k] = max(-prices[ind]+solve(ind+1, 0, k, prices, dp), solve(ind+1, 1, k, prices, dp));
        }
        return dp[ind][buy][k] = max(prices[ind]+solve(ind+1, 1, k-1, prices, dp), solve(ind+1, 0, k, prices, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int> (k+1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};