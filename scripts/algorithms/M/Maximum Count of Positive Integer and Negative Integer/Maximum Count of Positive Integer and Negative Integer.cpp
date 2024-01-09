// Runtime: 6 ms (Top 98.29%) | Memory: 18.00 MB (Top 55.02%)

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin(), pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0); 
        return max(neg, pos); 
    }
};
