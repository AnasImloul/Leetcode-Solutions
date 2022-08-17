class Solution(object):
    def triangularSum(self, nums):
        while len(nums) > 1:
            arr = []
            for i in range(len(nums)-1):
                arr.append((nums[i] + nums[i+1]) % 10)
            nums = arr
        return nums[0]
