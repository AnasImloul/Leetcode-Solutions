class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:        
        return list(accumulate([nums[0] ^ 2 ** maximumBit - 1] + nums[1:], ixor))[::-1]
