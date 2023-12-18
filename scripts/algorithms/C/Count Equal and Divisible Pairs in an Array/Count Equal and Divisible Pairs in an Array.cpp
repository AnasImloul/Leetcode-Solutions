// Runtime: 7 ms (Top 71.04%) | Memory: 12.30 MB (Top 39.13%)

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
                if(nums[i]==nums[j] && i*j%k==0)
                {
                    count++;
                }
        }
        return count;
    }
};
