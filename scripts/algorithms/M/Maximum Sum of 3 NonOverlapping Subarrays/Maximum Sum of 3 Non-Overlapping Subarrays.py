# Runtime: 1154 ms (Top 5.03%) | Memory: 57.1 MB (Top 5.03%)
from itertools import accumulate
from functools import lru_cache

class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        windows = list(accumulate(nums))
        windows = [windows[i+k-1]-(windows[i-1] if i>0 else 0) for i in range(len(windows)-k+1)]

        @lru_cache(None)
        def dfs(i, t):
            if t == 0:
                return 0, []
            if i >= len(windows):
                return float('-inf'), []
            cost1, sol1 = dfs(i+k, t-1)
            cost2, sol2 = dfs(i+1, t)
            if windows[i] + cost1 < cost2:
                return cost2, sol2
            return windows[i] + cost1, [i]+sol1
        return dfs(0, 3)[1]