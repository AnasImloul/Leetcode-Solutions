// Runtime: 16 ms (Top 92.85%) | Memory: 13.7 MB (Top 67.83%)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = nums[k-1] - nums[0];
        for (int i = k; i < nums.size(); i++) res = min(res, nums[i] - nums[i-k+1]);
        return res;
    }
};