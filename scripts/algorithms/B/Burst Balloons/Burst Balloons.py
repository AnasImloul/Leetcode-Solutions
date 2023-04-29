from functools import cache

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        length = len(nums)
        dp = [[None]*(length+1) for i in range(length+1)]
        
        @cache
        def dfs(l,r):
            if l>r: return 0
            if dp[l][r] is not None: return dp[l][r]
            dp[l][r] = 0
            for i in range(l,r+1):
                coins = dfs(l, i-1) + dfs(i+1, r) + nums[l-1]*nums[i]*nums[r+1]
                dp[l][r] = max(dp[l][r], coins)
            return dp[l][r]
        return dfs(1, length-2)