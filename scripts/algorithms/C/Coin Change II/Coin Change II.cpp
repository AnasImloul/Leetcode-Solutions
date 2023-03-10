class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;  //there always 1 way to pay a amount of 0 that is => do not pay
        
        for (int i = 0; i < coins.size(); i++)  // taking one coin at a time to avoid the permutation
          for (int j = coins[i]; j < dp.size(); j++) 
              dp[j] += dp[j - coins[i]];

        return dp[amount];
    }
};