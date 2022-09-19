// Runtime: 319 ms (Top 70.63%) | Memory: 37 MB (Top 67.84%)
class Solution {
public:
    int totsum;
    bool findans(vector<set<int>>& dp, vector<int>& nums, int start, int sum, int bitcnt){
        if(start==nums.size()){
            for(int i=0; i<dp.size(); i++)
                if(i+bitcnt!= 0 && i+bitcnt!= nums.size() && ((i+bitcnt)*totsum)%nums.size() == 0 && dp[i].find((((i+bitcnt)*totsum)/nums.size()) - sum)!=dp[i].end())
                    return true;
            return false;
        }
        return findans(dp, nums, start+1, sum, bitcnt) || findans(dp, nums, start+1, sum+nums[start], bitcnt+1);
    }

    void filldp(vector<set<int>>& dp, vector<int>& nums, int start, int mask){
        if(start==nums.size()/2){
            int sum = 0, cnt=0;
            for(int i=0; i<nums.size(); i++)
                if(mask&(1<<i)){
                    sum += nums[i];
                    cnt++;
                }
            dp[cnt].insert(sum);
            return;
        }
        filldp(dp, nums, start+1, mask);
        filldp(dp, nums, start+1, mask^(1<<start));
    }

    bool splitArraySameAverage(vector<int>& nums) {
        totsum = 0;
        for(int i=0; i<nums.size(); i++)
            totsum += nums[i];
        vector<set<int>> dp(nums.size()/2 + 1);
        filldp(dp, nums, 0, 0);
        return findans(dp, nums, nums.size()/2, 0, 0);
    }
};