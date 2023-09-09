// Runtime: 13 ms (Top 41.4%) | Memory: 11.78 MB (Top 90.0%)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0, length = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length; i++) {
            int median = length / 2;
            result += abs(nums[i] - nums[median]);
        }
        return result;
    }
};