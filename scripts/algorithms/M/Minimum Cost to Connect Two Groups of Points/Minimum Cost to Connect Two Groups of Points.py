// Runtime: 345 ms (Top 92.68%) | Memory: 29.40 MB (Top 24.39%)

class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        m, n = len(cost), len(cost[0])
        mn = [min(x) for x in zip(*cost)] # min cost of connecting points in 2nd group 
        
        @lru_cache(None)
        def fn(i, mask):
            """Return min cost of connecting group1[i:] and group2 represented as mask."""
            if i == m: return sum(mn[j] for j in range(n) if not (mask & (1<<j)))
            return min(cost[i][j] + fn(i+1, mask | 1<<j) for j in range(n))
                
        return fn(0, 0)
