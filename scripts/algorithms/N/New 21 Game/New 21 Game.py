# Runtime: 110 ms (Top 69.47%) | Memory: 14.5 MB (Top 12.98%)
class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        dp = collections.deque([float(i <= n) for i in range(k, k + maxPts)])
        s = sum(dp)
        for i in range(k):
            dp.appendleft(s / maxPts)
            s += dp[0] - dp.pop()

        return dp[0]