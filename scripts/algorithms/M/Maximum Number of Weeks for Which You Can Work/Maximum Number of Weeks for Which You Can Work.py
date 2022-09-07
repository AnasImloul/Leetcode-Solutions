# Runtime: 1032 ms (Top 59.60%) | Memory: 25.7 MB (Top 80.23%)
class Solution:
    def numberOfWeeks(self, m: List[int]) -> int:
        return min(sum(m), 2 * (sum(m) - max(m)) + 1)