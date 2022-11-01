# Runtime: 7624 ms (Top 5.13%) | Memory: 14.1 MB (Top 95.38%)
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        return min([v for v in fronts + backs if v not in set([i for i, j in zip(fronts, backs) if i == j])] or [0])