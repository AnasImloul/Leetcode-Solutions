class Solution { // YAA
public:
    
    int solve(vector<int>& nums, int target, int idx, unordered_map<string, int> &dp) {
        if(idx == nums.size()) {
            if(target == 0) {
                return 1;
            }
            return 0;
        }
        string key = to_string(idx) + " " + to_string(target);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        // +
        int x = solve(nums, target - nums[idx], idx+1, dp);
        // -
        int y = solve(nums, target + nums[idx], idx+1, dp);
        // sum
        return dp[key] = x+y;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return solve(nums, target, 0, dp);
    }
};