class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0, leftSum=0;
        for (int& n : nums){
            sum += n;
        }
        for(int i=0; i<nums.size();i++){
            if(leftSum == sum-leftSum-nums[i]){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
