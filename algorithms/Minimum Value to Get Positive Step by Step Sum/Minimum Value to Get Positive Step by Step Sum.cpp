class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int result=min(nums[0],0);
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
            result = min(result,nums[i]);
        }
        return abs(result)+1;
    }
};
