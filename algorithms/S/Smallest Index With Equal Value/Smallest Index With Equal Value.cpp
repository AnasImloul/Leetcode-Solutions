class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int i = 0;
        while (i < nums.size() && i % 10 != nums[i]) i++;
        return i >= nums.size() ? -1 : i;
    }
};
