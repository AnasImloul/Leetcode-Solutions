class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        for index in range(1, len(nums)):
            if(nums[index] != nums[index-1]):
                nums[i] = nums[index]
                i += 1
        return i
