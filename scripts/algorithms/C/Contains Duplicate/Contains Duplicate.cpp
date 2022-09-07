// Runtime: 116 ms (Top 79.99%) | Memory: 46.6 MB (Top 80.24%)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0; i<n-1; i++){
            if (nums[i]==nums[i+1])
        return true;
            }
        return false;

    }
};