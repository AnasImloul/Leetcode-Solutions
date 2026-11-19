# Runtime: 4 ms (Top 48.82%) | Memory: 19.20 MB (Top 80.30%)

class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        return sum(x for i, x in enumerate(nums) if bin(i).count('1') == k)
