// Runtime: 6 ms (Top 90.54%) | Memory: 8.5 MB (Top 90.65%)
class Solution {
public:
    void fun(vector<int>& nums, vector<vector<int>>&ans,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        int freq[21]={0};
        for(int j=i;j<nums.size();j++)
        {
            if(freq[nums[j]+10]==0)
            {
            swap(nums[i],nums[j]);
            fun(nums,ans,i+1);
            swap(nums[i],nums[j]);
            }
            freq[nums[j]+10]++;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        fun(nums,ans,0);
        return ans;
    }
};