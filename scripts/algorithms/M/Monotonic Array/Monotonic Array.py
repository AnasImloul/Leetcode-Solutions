class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        counter = 0
        for i in range(len(nums) - 1):
            if nums[i] >= nums[i + 1]:
                counter += 1
        if counter == len(nums) - 1:
            return True
        counter = 0
        for i in range(len(nums) - 1):
            if nums[i] <= nums[i + 1]:
                counter += 1
        if counter == len(nums) - 1:
            return True
        return False
