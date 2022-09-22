// Runtime: 363 ms (Top 33.60%) | Memory: 65.6 MB (Top 68.46%)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int minElePossible=0,ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minElePossible){
                ans+=minElePossible-nums[i];
                nums[i]+=minElePossible-nums[i];
            }
            minElePossible=nums[i]+1;
        }
        return ans;
    }
};