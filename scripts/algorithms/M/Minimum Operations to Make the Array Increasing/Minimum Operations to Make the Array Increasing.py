# Runtime: 357 ms (Top 5.07%) | Memory: 14.8 MB (Top 8.90%)
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums)-1):
            if nums[i] >= nums[i+1]:
                count += (nums[i]+1)-nums[i+1]
                nums[i+1] = nums[i]+1
        return count