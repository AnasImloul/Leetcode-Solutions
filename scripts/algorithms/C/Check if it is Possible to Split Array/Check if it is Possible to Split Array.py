# Runtime: 53 ms (Top 77.9%) | Memory: 16.33 MB (Top 56.9%)

class Solution:
    def canSplitArray(self, nums: List[int], m: int) -> bool:

        return len(nums) < 3 or max(map(sum, pairwise(nums))) >= m 