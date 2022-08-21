# Runtime: 3516 ms (Top 53.70%) | Memory: 22.1 MB (Top 43.52%)

from bisect import bisect_left
from functools import lru_cache
class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        start = locations[start]
        end = locations[finish]
        locations.sort()
        start = bisect_left(locations, start)
        end = bisect_left(locations, end)
        @lru_cache(None)
        def dfs(i, fuel):
            if fuel == 0 and i == end: return 1
            res = 0
            if i == end: res += 1
            j = i-1
            while j>=0 and abs(locations[j]-locations[i]) <= fuel:
                res += dfs(j, fuel-abs(locations[j]-locations[i]))
                j -= 1
            j = i+1
            while j<len(locations) and abs(locations[j]-locations[i]) <= fuel:
                res += dfs(j, fuel-abs(locations[j]-locations[i]))
                j += 1
            return res
        return dfs(start, fuel) % (10**9+7)