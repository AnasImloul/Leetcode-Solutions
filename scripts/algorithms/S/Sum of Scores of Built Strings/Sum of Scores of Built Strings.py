// Runtime: 200 ms (Top 85.96%) | Memory: 25.20 MB (Top 24.56%)

class Solution:
    def sumScores(self, s):
        n = len(s)

        dp, ans, j = [1]*n, [0]*n, 0 

        for i in range(1,n):
            while s[i] != s[j] and j > 0:
                j = ans[j-1]

            if s[i] == s[j]:
                dp[i] += dp[j]
                ans[i] = j+1
                j += 1 

        return sum(dp)







        
