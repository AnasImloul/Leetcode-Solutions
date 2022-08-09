class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
     int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2){
            res+=min(nums[i],nums[i+1]);  
        }
        return res;
    }
};
