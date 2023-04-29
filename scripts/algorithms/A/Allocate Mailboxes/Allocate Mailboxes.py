class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        houses.sort()

        @lru_cache(None)
        def dp(left, right, k):
            if k == 1:                                          # <-- 1.
                mid = houses[(left+right) // 2]
                return sum(abs(houses[i] - mid) for i in range(left, right + 1))

            return min(dp(left, i, 1) + dp(i+1, right, k - 1) 
                       for i in range(left, right - k + 2))     # <-- 2.

        return dp(0, len(houses)-1, k)