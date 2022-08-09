class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts = [0] + sorted(cuts) + [n]
        k = len(cuts)
        dp = [[float('inf')] * k for _ in range(k)]
        for l in range(1, k + 1):
            for beg in range(k - l):
                end = beg + l
                if l == 1:
                    dp[beg][end] = 0
                    continue
                for i in range(beg + 1, end):
                    currcost = cuts[end] - cuts[beg]
                    currcost += dp[beg][i] + dp[i][end]
                    dp[beg][end] = min(dp[beg][end], currcost)
        return dp[0][k - 1]
