

class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        @cache
        def dp(i, p, h):
            if (h > target) or (i == m and h != target):
                return inf
            if i == m:
                return 0
            if houses[i] != 0:
                return dp(i + 1, houses[i], h + int(p != houses[i]))

            best = inf
            for j, c in enumerate(cost[i], 1):
                best = min(best, dp(i + 1, j, h + int(p != j)) + c)
            return best

        res = dp(0, 0, 0)
        return res if res != inf else -1
