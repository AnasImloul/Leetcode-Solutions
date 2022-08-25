// Runtime: 73 ms (Top 50.08%) | Memory: 13.8 MB (Top 59.64%)
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        res, i, N = 0, 0, len(cost)
        while i < N:
            res += sum(cost[i : i + 2])
            i += 3
        return res