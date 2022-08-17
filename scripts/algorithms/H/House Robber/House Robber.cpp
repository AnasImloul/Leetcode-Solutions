class Solution {
public:
    int helper(int i, vector<int>& nums) {
        if(i == 0) return nums[i];
        if(i < 0) return 0;

        int pick = nums[i] + helper(i-2, nums);
        int not_pick = 0 + helper(i-1, nums);

        return max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        return helper(nums.size()-1, nums);
    }
};
