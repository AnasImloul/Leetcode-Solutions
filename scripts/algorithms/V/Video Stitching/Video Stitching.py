# Runtime: 46 ms (Top 41.2%) | Memory: 16.25 MB (Top 82.7%)

class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        dp = [float('inf')] * (T + 1)
        dp[0] = 0
        for i in range(1, T + 1):
            for start, end in clips:
                if start <= i <= end:
                    dp[i] = min(dp[start] + 1, dp[i])
        if dp[T] == float('inf'):
            return -1
        return dp[T]