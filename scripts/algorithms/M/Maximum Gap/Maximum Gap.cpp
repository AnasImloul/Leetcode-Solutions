// Runtime: 1034 ms (Top 5.00%) | Memory: 142.3 MB (Top 5.23%)

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res;
        int maxx=INT_MIN;
        map<int,int> m;
        if(nums.size()==1)
            return 0;
        for(int i =0;i<nums.size()-1;i++)
        {
            m[i]=nums[i+1]-nums[i];
        }
        for(auto it: m)
        {
            if(it.second>maxx)
            {
                maxx=it.second;
            }
        }
        return maxx;
    }
};
