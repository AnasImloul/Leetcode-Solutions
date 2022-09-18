// Runtime: 248 ms (Top 14.67%) | Memory: 67.8 MB (Top 53.58%)
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int m = INT_MIN, sm = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sm += nums[i];
            m = max(sm, m);
            if (sm < 0) sm = 0;
        }
        return m;
    }
};