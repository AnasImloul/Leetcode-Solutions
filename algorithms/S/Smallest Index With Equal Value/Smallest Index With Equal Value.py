class Solution(object):
    def smallestEqual(self, nums, i=0):
        return -1 if i == len(nums) else ( i if i%10 == nums[i] else self.smallestEqual(nums, i+1) )