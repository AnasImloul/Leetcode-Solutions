from functools import lru_cache
class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        @lru_cache(None)
        def dfs(t):
            if t == 0: return 0
            res = float('-inf')
            for digit in range(1,10):
                if t - cost[digit-1] >= 0:
                    res = max(res, dfs(t - cost[digit-1])*10+digit)
            return res
        res = dfs(target)
        return "0" if res == float('-inf') else str(res)