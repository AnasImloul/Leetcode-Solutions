# Runtime: 1580 ms (Top 22.92%) | Memory: 22.4 MB (Top 66.92%)
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m= len(s)
        n= len(p)

        dp = [[False]*(n+1) for i in range(m+1)]

        dp[0][0] = True

        for j in range(len(p)):
            if p[j] == "*":
                dp[0][j+1] = dp[0][j]

        for i in range(1,m+1):
            for j in range(1,n+1):
                if p[j-1] == "*":
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]

                elif s[i-1] == p[j-1] or p[j-1] == "?":
                    dp[i][j] = dp[i-1][j-1]

        return dp[-1][-1]