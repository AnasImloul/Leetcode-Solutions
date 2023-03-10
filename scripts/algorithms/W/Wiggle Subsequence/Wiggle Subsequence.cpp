class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(nums.size(),0));
        int ans = 1, high, low;
        dp[0][0] = dp[1][0] = 1;
        for(int i=1; i<nums.size(); ++i){
            high = low = 0;
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j]) low = max(low, dp[1][j]);
                else if(nums[i]<nums[j]) high = max(high, dp[0][j]);
            }
            dp[0][i] = low + 1;
            dp[1][i] = high + 1;
            ans = max({ans, dp[0][i], dp[1][i]});
        }
        return ans;
    }
};