class Solution:
    def numberOfWeeks(self, m: List[int]) -> int:
        return min(sum(m), 2 * (sum(m) - max(m)) + 1)
