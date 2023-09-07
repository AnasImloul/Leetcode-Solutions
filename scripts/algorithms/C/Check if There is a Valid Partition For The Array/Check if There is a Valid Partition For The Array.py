# Runtime: 920 ms (Top 32.4%) | Memory: 30.14 MB (Top 95.0%)

class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        
        dp = [False] * 3
        dp[0] = True  # An empty partition is always valid

        for i in range(2, n + 1):
            ans = False

            if nums[i - 1] == nums[i - 2]:
                ans = ans or dp[(i - 2) % 3]
            if i >= 3 and nums[i - 1] == nums[i - 2] == nums[i - 3]:
                ans = ans or dp[(i - 3) % 3]
            if i >= 3 and nums[i - 1] == nums[i - 2] + 1 == nums[i - 3] + 2:
                ans = ans or dp[(i - 3) % 3]

            dp[i % 3] = ans

        return dp[n % 3]