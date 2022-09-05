// Runtime: 6 ms (Top 60.42%) | Memory: 7.2 MB (Top 56.55%)
class Solution {
public:

    int subsetXORSum(vector<int>& nums)
    {
        int ans=0;
        for(int i=0; i<32; i++)
        {
            int mask=1<<i;
            int count=0;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[j]&mask) count++;
            }
            if(count)
            {
                ans+=mask*(1<<(count-1))*(1<<(nums.size()-count));
            }
        }
        return ans;
    }
};