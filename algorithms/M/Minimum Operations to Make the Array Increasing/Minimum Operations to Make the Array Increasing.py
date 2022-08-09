class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums)-1):
            if nums[i] >= nums[i+1]:
                count += (nums[i]+1)-nums[i+1]
                nums[i+1] = nums[i]+1
        return count
