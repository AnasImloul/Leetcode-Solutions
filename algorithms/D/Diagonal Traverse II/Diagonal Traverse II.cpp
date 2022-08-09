class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = 0;
        for(vector<int> &v : nums)
        {
            int y = v.size();
            m = max(m, y);
        }
        vector<int> D2[n+m-1];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                D2[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n+m-1; i++)
        {
            int x = D2[i].size();
            while(x--)
            {
                ans.push_back(D2[i][x]);
                D2[i].pop_back();
            }
        }
        return ans;
    }
};
