// Runtime: 68 ms (Top 11.26%) | Memory: 16.5 MB (Top 13.92%)
class Solution {
public:

    int solve(vector<int>&piles, int i, int j, vector<vector<int>>&dp){

        if(i==j)
            return piles[i];

        if(dp[i][j]!=-1)
            return dp[i][j];

        return dp[i][j] = max((piles[i] + solve(piles, i+1, j, dp)), (piles[j] + solve(piles, i, j-1, dp)));

    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return solve(piles, 0, n-1, dp);
    }
};