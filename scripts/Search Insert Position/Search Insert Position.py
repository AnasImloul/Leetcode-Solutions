class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for num in nums:
            if target in nums:
                return nums.index(target)
            elif num > target:
                return nums.index(num)
            elif num == nums[-1]:
                return len(nums)
