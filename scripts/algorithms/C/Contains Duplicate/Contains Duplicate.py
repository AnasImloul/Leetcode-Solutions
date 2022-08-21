# Runtime: 714 ms (Top 44.74%) | Memory: 26.1 MB (Top 5.18%)

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))