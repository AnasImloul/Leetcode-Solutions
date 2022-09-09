# Runtime: 72 ms (Top 49.84%) | Memory: 13.8 MB (Top 58.81%)
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        res, i, N = 0, 0, len(cost)
        while i < N:
            res += sum(cost[i : i + 2])
            i += 3
        return res