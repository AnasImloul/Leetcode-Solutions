class Solution
{
    public:
        int countPalindromicSubsequences(string s)
        {
            int n = s.size();
            long dp[n + 1][n + 1];
            memset(dp, 0, sizeof dp);
            long MOD = 1e9 + 7;
            for (int i = n - 1; i >= 0; i--)
            {
                dp[i][i] = 1;
                for (int j = i + 1; j < n; j++)
                {
                    if (s[i] != s[j])
                        dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1] *2;
                        int left = i + 1, right = j - 1;
                        while (left <= right && s[left] != s[i]) left++;
                        while (left <= right && s[right] != s[i]) right--;
                        if (left > right)
                            dp[i][j] += 2;
                        else if (left == right)
                            dp[i][j] += 1;
                        else
                            dp[i][j] -= dp[left + 1][right - 1];
                    }
                    dp[i][j] = (dp[i][j] + MOD) % MOD;
                }
            }
            return (int) dp[0][n - 1];
        }
};
