# Runtime: 3535 ms (Top 25.64%) | Memory: 35.60 MB (Top 22.12%)

class Solution:
    def lengthOfLongestSubsequence(self, nums, sum):
        n = len(nums)
        dp = [[-1] * (sum + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 0

        for i in range(1, n + 1):
            for j in range(1, sum + 1):
                dp[i][j] = dp[i - 1][j]
                if j >= nums[i - 1] and dp[i - 1][j - nums[i - 1]] != -1:
                    dp[i][j] = max(1 + dp[i - 1][j - nums[i - 1]], dp[i][j])

        return dp[n][sum]
