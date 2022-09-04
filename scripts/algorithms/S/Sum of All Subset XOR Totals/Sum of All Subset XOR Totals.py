# Runtime: 60 ms (Top 83.44%) | Memory: 13.8 MB (Top 70.65%)
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def sums(term, idx):
            if idx == len(nums):
                return term
            return sums(term, idx + 1) + sums(term ^ nums[idx], idx + 1)

        return sums(0, 0)