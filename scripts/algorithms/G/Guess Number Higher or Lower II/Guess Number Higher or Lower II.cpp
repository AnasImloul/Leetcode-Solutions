// Runtime: 226 ms (Top 55.81%) | Memory: 8.2 MB (Top 44.55%)
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int start, int end)
    {
        if(start>= end)
            return 0;

        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = 0;
        int result = INT_MAX;
        for(int i=start; i<=end; i++)
        {
            int left = solve(start,i-1);
            int right = solve(i+1,end);
            ans = max(left,right) + i; // this line gurantee to include the money that is needed to win higher values
            result = min(ans,result);
        }

        return dp[start][end] = result;
    }

    int getMoneyAmount(int n) {
        int ans = 0;
        dp = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return solve(1,n);
    }
};