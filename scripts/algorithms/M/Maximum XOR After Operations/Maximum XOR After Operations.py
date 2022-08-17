class Solution:
    def maximumXOR(self, nums: List[int]) -> int:
        res=0
        for i in nums:
            res |= i
        return res
