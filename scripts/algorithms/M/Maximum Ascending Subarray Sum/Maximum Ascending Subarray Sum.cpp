// Runtime: 0 ms (Top 100.00%) | Memory: 8.5 MB (Top 42.32%)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = nums[0], curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                curr += nums[i];
            }
            else {
                max_sum = max(max_sum, curr);
                curr = nums[i];
            }
        }
        return max(max_sum, curr);
    }
};