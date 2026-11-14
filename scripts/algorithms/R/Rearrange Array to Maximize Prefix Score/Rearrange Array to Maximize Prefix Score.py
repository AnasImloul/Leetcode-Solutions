# Runtime: 101 ms (Top 34.15%) | Memory: 31.20 MB (Top 90.24%)

class Solution:
    def maxScore(self, nums: List[int]) -> int:
        return sum(n > 0 for n in accumulate(sorted(nums, reverse=True)))
