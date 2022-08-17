class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size()-1;
        }
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int result = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > max1){
                result = i;
                max2 = max1;
                max1 = nums[i];
            }else if(nums[i] > max2){
                max2 = nums[i];
            }
        }
        return max1 >= 2*max2 ? result : -1;
    }
};
