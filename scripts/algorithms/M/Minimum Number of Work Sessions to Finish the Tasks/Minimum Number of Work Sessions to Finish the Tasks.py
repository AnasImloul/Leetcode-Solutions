// Runtime: 966 ms (Top 45.98%) | Memory: 41.80 MB (Top 22.32%)

class Solution:
    def minSessions(self, tasks, T):
        n = len(tasks)

        @lru_cache(None)
        def dp(mask):
            if mask == 0: return (1, 0)
            ans = (float("inf"), float("inf"))
            for j in range(n):
                if mask & (1<<j):
                    pieces, last = dp(mask - (1 << j))
                    full = (last + tasks[j] > T)
                    ans = min(ans, (pieces + full, tasks[j] + (1-full)*last))  
            return ans

        return dp((1<<n) - 1)[0]
