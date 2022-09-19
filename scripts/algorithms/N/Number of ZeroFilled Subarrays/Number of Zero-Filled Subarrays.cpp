// Runtime: 369 ms (Top 9.12%) | Memory: 107.6 MB (Top 15.93%)
class Solution
{
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long count = 0;
        long long ans = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                count++;
                ans += count;
            }
            else
            {
                count = 0;
            }
        }
        return ans;
    }

};