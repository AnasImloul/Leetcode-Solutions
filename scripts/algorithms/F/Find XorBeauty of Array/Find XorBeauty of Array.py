// Runtime: 276 ms (Top 82.02%) | Memory: 31.20 MB (Top 34.83%)

class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        return reduce(xor, nums)  
