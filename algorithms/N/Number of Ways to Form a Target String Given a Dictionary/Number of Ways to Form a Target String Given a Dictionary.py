from collections import defaultdict
from functools import lru_cache
class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        M = 10**9 + 7
        dt = defaultdict(int)
        m, n = len(words[-1]), len(target)
        for word in words:
            for i, c in enumerate(word):
                dt[i,c] += 1
        @lru_cache(None)
        def dfs(i,j):
            if j == n: return 1
            if i == m: return 0
            res = 0
            if dt[i,target[j]]:
                res = (res + dt[i,target[j]]*dfs(i+1,j+1))%M
            res = (res + dfs(i+1,j))%M
            return res
        return dfs(0,0)