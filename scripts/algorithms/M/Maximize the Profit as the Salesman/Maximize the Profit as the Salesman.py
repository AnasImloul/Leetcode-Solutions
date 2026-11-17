# Runtime: 346 ms (Top 19.78%) | Memory: 42.10 MB (Top 78.02%)

class Solution:
    def maximizeTheProfit(self, n: int, offers: List[List[int]]) -> int:

        dp = [[0,0]]           

        f = lambda x: dp[bisect_left(dp,[x+1])-1][1] 

        for s, e, p in sorted(offers, key = lambda x: x[1]):

            dp.append([e+1, max(f(e+1),f(s)+p)])

        return dp[-1][1]
