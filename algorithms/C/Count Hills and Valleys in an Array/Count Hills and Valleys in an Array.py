class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        c = 0
        i = 1
        while i <len(nums)-1:
            j = i+1
            while j < len(nums)-1 and nums[j] == nums[i]:
                j += 1
            if (nums[i-1] > nums[i] and nums[j] > nums[i]) or (nums[i-1] < nums[i] and nums[j] < nums[i]):
                    c += 1
            i = j
        return c
