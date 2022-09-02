# Runtime: 145 ms (Top 75.66%) | Memory: 15.5 MB (Top 23.89%)
class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        return max(0, max(nums)-min(nums)-2*k)