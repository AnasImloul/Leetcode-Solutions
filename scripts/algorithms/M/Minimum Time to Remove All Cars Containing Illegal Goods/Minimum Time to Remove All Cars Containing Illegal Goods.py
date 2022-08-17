class Solution:
    def minimumTime(self, s):
        def minSum(nums):
            dp = [0]*len(nums)
            dp[0] = nums[0]
            for i in range(1, len(nums)):
                dp[i] = min(nums[i], nums[i] + dp[i-1])
            return min(0, min(dp))

        n = len(s)
        s1 = [1 if i == "1" else -1 for i in s]
        score = minSum(s1)
       
        return n + score
