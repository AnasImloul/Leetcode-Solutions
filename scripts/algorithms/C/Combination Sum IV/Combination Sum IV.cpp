// Runtime: 8 ms (Top 12.71%) | Memory: 6.8 MB (Top 29.75%)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto x : nums) {
                if (x <= i) {
                    dp[i] += dp[i - x];
                }
            }
        }
        return dp[target];
    }
};