# Runtime: 408 ms (Top 21.69%) | Memory: 15.6 MB (Top 65.11%)
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.

        """
        notzero = 0
        zero = 0

        while notzero < len(nums):
            if nums[notzero] != 0:
                nums[zero] , nums[notzero] = nums[notzero], nums[zero]
                zero += 1
            notzero += 1