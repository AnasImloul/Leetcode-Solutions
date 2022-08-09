class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();      
         sort(nums.begin(), nums.end());                
       return (nums[n -1]-1)* (nums[n-2]-1);
    }
};
