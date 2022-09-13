// Runtime: 236 ms (Top 97.78%) | Memory: 172.2 MB (Top 58.73%)
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        long long z=0,o=0,t=0;
        long long mod =1e9 +7;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                z=(z+z+1)%mod;
            else if(nums[i]==1)
                o=(o+o+z)%mod;
            else
                t=(t+t+o)%mod;
        }
        return (((t%mod)+mod)%mod);
    }
};