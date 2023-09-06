# Runtime: 42 ms (Top 60.3%) | Memory: 16.30 MB (Top 27.0%)

class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        return max(1, 1 - min(accumulate(nums)))