class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0], res = 0;
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};
