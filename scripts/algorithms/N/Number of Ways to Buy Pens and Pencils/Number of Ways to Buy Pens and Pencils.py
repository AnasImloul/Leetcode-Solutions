class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        return sum((total - pens*cost1) // cost2 + 1 for pens in range(total // cost1 + 1))