from functools import lru_cache

class Solution:
    def maxScore(self, nums: List[int]) -> int:
        def gcd(a, b):
            while a:
                a, b = b%a, a
            return b
        halfplus = len(nums)//2 + 1
        @lru_cache(None)
        def dfs(mask, k):
            if k == halfplus:
                return 0
            res = 0
            for i in range(len(nums)):
                for j in range(i+1, len(nums)):
                    if not(mask & (1<<i)) and not(mask &(1<<j)):
                        res = max(res, k*gcd(nums[i], nums[j])+dfs(mask|(1<<i)|(1<<j), k+1))
            return res
        return dfs(0, 1)
