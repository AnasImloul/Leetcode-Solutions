class Solution {
public:
    void per(int ind, int n, vector<int>&nums, vector<vector<int>> &ans)
    {
        if(ind==n)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            swap(nums[ind],nums[i]);
            per(ind+1,n,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        per(0,n,nums,ans);
        return ans;
    }
};
