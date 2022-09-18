# Runtime: 7454 ms (Top 7.46%) | Memory: 705.2 MB (Top 26.87%)
class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        MOD = 10**9 + 7
        @lru_cache(None)
        def dp(i, k, isStart):
            if k == 0: return 1 # Found a way to draw k valid segments
            if i == n: return 0 # Reach end of points
            ans = dp(i+1, k, isStart) # Skip ith point
            if isStart:
                ans += dp(i+1, k, False) # Take ith point as start
            else:
                ans += dp(i, k-1, True) # Take ith point as end
            return ans % MOD
        return dp(0, k, True)