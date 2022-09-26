// Runtime: 513 ms (Top 42.13%) | Memory: 55.3 MB (Top 76.34%)
class Solution {
public:
    static bool cmp(string &a,string &b)
    {
        if(a.size()==b.size())
        {
            return a<b;
        }
        return a.size()<b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k)
    {
        sort(nums.begin(),nums.end(),cmp);
        int n=nums.size();
        return nums[n-k];
    }
};