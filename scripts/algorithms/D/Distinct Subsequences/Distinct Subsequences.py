# Runtime: 1092 ms (Top 41.44%) | Memory: 70.6 MB (Top 63.39%)
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        if len(t) > len(s):
            return 0
        ls, lt = len(s), len(t)
        res = 0
        dp = [[0] * (ls + 1) for _ in range(lt + 1)]
        for j in range(ls + 1):
            dp[-1][j] = 1
        for i in range(lt - 1, -1, -1):
            for j in range(ls -1 , -1, -1):
                dp[i][j] = dp[i][j + 1]
                if s[j] == t[i]:

                    dp[i][j] += dp[i + 1][j + 1]
        return dp[0][0]