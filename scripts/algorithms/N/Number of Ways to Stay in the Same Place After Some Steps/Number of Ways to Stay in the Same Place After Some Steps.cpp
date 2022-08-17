class Solution {
public:
    int n, MOD = 1e9 + 7;
    int numWays(int steps, int arrLen) {
        n = arrLen;
        vector<vector<int>> memo(steps / 2 + 1, vector<int>(steps + 1, -1));
        return dp(memo, 0, steps) % MOD;
    }
    long dp(vector<vector<int>>& memo, int i, int steps){
        if(steps == 0)
            return i == 0;
        if(i < 0 || i == n || i > steps)
            return 0;
        if(memo[i][steps] != -1)
            return memo[i][steps];
        return memo[i][steps] = (dp(memo, i, steps - 1) + dp(memo, i - 1, steps - 1) + dp(memo, i + 1, steps - 1)) % MOD;
    }
};

