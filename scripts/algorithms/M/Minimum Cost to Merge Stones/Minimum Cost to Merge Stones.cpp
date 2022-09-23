// Runtime: 15 ms (Top 24.35%) | Memory: 8.4 MB (Top 28.20%)
class Solution {
public:
    //Similar to Matrix Chain Multiplication optimization
    vector<int> presum;
    int solve(vector<int>& stones, int k, int left, int right, vector<vector<int>>& dp){
        if(right == left) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int res = 1e9;
        for(int i = left; i < right; i=i+k-1){
            res = min(res, solve(stones, k, left, i, dp) + solve(stones, k, i+1, right, dp));
        }

        //this cumulative sum evaluation separately, as that of MCX
        if((right - left)%(k-1) ==0){
            res += presum[right+1] - presum[left];
        }
        return dp[left][right] = res;
    }

    int mergeStones(vector<int>& stones, int k) {
        if((stones.size() - 1)%(k-1) != 0) return -1;
        presum.push_back(0);
        for(auto s: stones) presum.push_back(s + presum.back());
        vector<vector<int>> dp(32, vector<int> (32, -1));
        return solve(stones, k, 0, stones.size()-1, dp);
    }
};