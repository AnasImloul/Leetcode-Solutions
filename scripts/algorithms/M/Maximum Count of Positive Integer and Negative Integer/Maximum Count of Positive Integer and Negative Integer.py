// Runtime: 97 ms (Top 98.5%) | Memory: 17.70 MB (Top 15.05%)

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        neg = bisect_left(nums, 0)
        pos = len(nums) - bisect_right(nums, 0)
        return max(neg, pos)
