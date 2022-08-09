from functools import lru_cache
class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        houses.sort()
        n = len(houses)
        @lru_cache(None)
        def cost(i,j):
            cost = 0
            while i < j:
                cost += houses[j]-houses[i]
                i += 1
                j -= 1
            return cost
        @lru_cache(None)
        def dfs(i,k):
            if i == n:
                return 0
            if k == 0:
                return float('inf')
            res = float('inf')
            for j in range(i,n):
                res = min(res,cost(i,j)+dfs(j+1,k-1))
            return res
        return dfs(0,k)
