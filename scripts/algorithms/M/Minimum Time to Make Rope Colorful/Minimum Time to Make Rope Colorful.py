# Runtime: 862 ms (Top 94.6%) | Memory: 27.26 MB (Top 71.4%)

class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        ans = prev = 0 # index of previously retained letter 
        for i in range(1, len(s)): 
            if s[prev] != s[i]: prev = i
            else: 
                ans += min(cost[prev], cost[i])
                if cost[prev] < cost[i]: prev = i
        return ans 