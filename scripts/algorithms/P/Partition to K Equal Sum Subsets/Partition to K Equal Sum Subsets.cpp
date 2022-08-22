// Runtime: 2009 ms (Top 12.75%) | Memory: 101 MB (Top 5.10%)
class Solution {
public:
    unordered_map<string, int> dp;
    int solve(vector<int>& nums, int target, int remain, int i, int vis, int k){
        if( k == 1) return 1;

        //memorization addition
        string t = to_string(i)+"_"+to_string(remain)+"_"+to_string(k)+"_"+to_string(vis);
        if(dp.find(t) != dp.end()) return dp[t];

        if(remain == 0){
            return dp[t] = solve(nums, target, target, nums.size()-1, vis, k - 1);
        }
        for(int j = i; j >= 0; --j){
            if(((vis>>j)& 1) || remain - nums[j] < 0) continue;
            vis = vis | (1 << j );
            if(solve(nums, target, remain - nums[j], j - 1, vis, k) ) return dp[t] = 1;
            vis = vis & ~(1<<j);
        }
        return dp[t] = 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k != 0) return false;
        int vis = 0;
        return solve(nums, sum/k, sum/k, nums.size()-1, vis, k);
    }
};