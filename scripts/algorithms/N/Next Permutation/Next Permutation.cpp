// Runtime: 3 ms (Top 90.34%) | Memory: 12.1 MB (Top 74.79%)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)
            return;

        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j=nums.size()-1;
            while(nums[i] >= nums[j]) j--;
            swap(nums[j], nums[i]);
        }
        sort(nums.begin()+i+1, nums.end());
    }
};