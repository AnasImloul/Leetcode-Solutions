class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs)
        m = n // 2
        
        @lru_cache(None)
        def dfs(cur, a):
			# cur is the current user index
			# `a` is the number of people travel to city `a`
			
            if cur == n:
                return 0
            
			# people to b city
            b = cur - a
            ans = float('inf')
            
			# the number of people to `a` city number did not reach to limit, 
			# then current user can trval to city `a`
			
            if a < m:
                ans = min(dfs(cur+1, a+1)+costs[cur][0], ans)
            
			# the number of people to `b` city number did not reach to limit
			# then current user can trval to city `b`
            if b < m:
                ans = min(dfs(cur+1, a)+costs[cur][1], ans)
                
            return ans
        
        return dfs(0, 0)
