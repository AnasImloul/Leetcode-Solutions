class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        return max(sum(n & (1 << i) > 0 for n in candidates) for i in range(0, 24))
