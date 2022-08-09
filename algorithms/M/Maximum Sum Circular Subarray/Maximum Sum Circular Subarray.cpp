class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
    int currsummin=nums[0],ansmin=nums[0],currsummax=nums[0],ansmax=nums[0],sum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum+=nums[i];
            
            currsummin=min(nums[i],currsummin+nums[i]);
            ansmin=min(ansmin,currsummin);
            
            currsummax=max(currsummax+nums[i],nums[i]);
            ansmax=max(ansmax,currsummax);
        }
        return ansmax>0 ? max(ansmax,sum-ansmin) : ansmax;
    }
};
