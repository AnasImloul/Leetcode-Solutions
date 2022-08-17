class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        for(int i = 1;i<nums.size();i++)
            ans[0]+=(nums[i]-nums[0]);
        
        for(int j = 1;j<nums.size();j++)
            ans[j] = ans[j-1]+(nums[j]-nums[j-1])*j-(nums[j]-nums[j-1])*(nums.size()-j);
        
        return ans;
    }
};
