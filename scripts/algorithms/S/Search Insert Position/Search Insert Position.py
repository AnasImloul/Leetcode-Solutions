class Solution:
    def searchInsert(self, nums, target):
        for i, num in enumerate(nums):
            if num >= target:
                return i
        return len(nums)