class Solution {
public:
   
    //same code as that of coin change
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i && dp[i-coins[j]] !=INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
 
    
    
    int minimumNumbers(int num, int k) {
    vector<int>res;
    for (int i = 0; i <= num; i++){
        if (i % 10 == k)
           res.push_back(i);
        }
       return coinChange(res, num);

       
    }
    
};
