class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int ans = 0;
    vector<int> dp(n, 0);
    for (int i = 1; i < n; ++i) {
      int max_dp = 0;
      for (int j = 0; j < i; ++j) {
        dp[i] = max(dp[i], prices[i] - prices[j] + max_dp);
        max_dp = max(max_dp, j > 0 ? dp[j - 1] : 0);
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
