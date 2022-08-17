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