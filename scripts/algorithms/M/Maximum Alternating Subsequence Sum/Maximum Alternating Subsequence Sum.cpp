class Solution {
public:
    long long dp[2][100001];
    long long util(int i, vector<int>&nums, bool isPos){
        if(i>=nums.size())return 0;
        if(dp[isPos][i]!=-1)return dp[isPos][i];
        long long curr = (isPos?nums[i]:-1*nums[i]);
        return dp[isPos][i] = max(curr + util(i+1, nums, !isPos), util(i+1, nums, isPos));
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return util(0, nums, true);
    }
};
