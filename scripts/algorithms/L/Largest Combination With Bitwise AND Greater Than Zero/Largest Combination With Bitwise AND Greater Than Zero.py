# Runtime: 2282 ms (Top 70.42%) | Memory: 24.8 MB (Top 77.26%)
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        return max(sum(n & (1 << i) > 0 for n in candidates) for i in range(0, 24))