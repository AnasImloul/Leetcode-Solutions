// Runtime: 22 ms (Top 99.63%) | Memory: 25.6 MB (Top 27.04%)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int> temp(nums.size());
        for(int i = 0; i < nums.size() ;i++){

            temp[(i+k)%nums.size()] = nums[i];

        }

        nums = temp;
    }
};