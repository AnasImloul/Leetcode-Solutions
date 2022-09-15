# Runtime: 127 ms (Top 14.40%) | Memory: 14 MB (Top 75.22%)
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = cost[:2] + [0]*(n-2)
        for i in range(2, n):
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
        return min(dp[-1], dp[-2])