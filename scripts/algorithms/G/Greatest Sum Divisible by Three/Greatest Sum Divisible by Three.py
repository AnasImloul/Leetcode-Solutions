# Runtime: 463 ms (Top 64.44%) | Memory: 20.3 MB (Top 40.95%)
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, float('-inf'), float('-inf')]
        for x in nums:
            dp_cp = dp[:]
            for left in range(3):
                right = (left + x) % 3
                dp[right] = max(dp_cp[right], dp_cp[left] + x)

        return dp[0]