class Solution:
   def isMatch(self, s, p):
       n = len(s)
       m = len(p)
       dp = [[False for _ in range (m+1)] for _ in range (n+1)]
       dp[0][0] = True
       for c in range(1,m+1):
           if p[c-1] == '*' and c > 1:
               dp[0][c] = dp[0][c-2]
       for r in range(1,n+1):
           for c in range(1,m+1):
               if p[c-1] == s[r-1] or p[c-1] == '.':
                   dp[r][c] = dp[r-1][c-1]
               elif c > 1 and p[c-1] == '*':
                   if  p[c-2] =='.' or s[r-1]==p[c-2]:
                       dp[r][c] =dp[r][c-2] or dp[r-1][c]
                   else:
                       dp[r][c] = dp[r][c-2]
       return dp[n][m]
