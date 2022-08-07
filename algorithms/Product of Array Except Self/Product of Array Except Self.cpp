class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0,product=1;
        for(auto i:nums){
            if(i==0)
                zero++;
            else product*=i;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0 && zero>1){
                nums[i]=0;
            }
            else if(nums[i] == 0){
                nums[i]=product;
            }
            else if(zero > 0){
                nums[i]=0;
            }
            else nums[i]=product/nums[i];
        }
        return nums;
    }
};
