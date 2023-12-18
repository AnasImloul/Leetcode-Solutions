// Runtime: 1076 ms (Top 41.88%) | Memory: 30.80 MB (Top 35.63%)

class Solution:
    def minimumRemoval(self, A: List[int]) -> int:
        return sum(A) - max((len(A) - i) * n for i, n in enumerate(sorted(A)))
