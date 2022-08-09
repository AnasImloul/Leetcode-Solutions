class Solution:
    def smallerNumbersThanCurrent(self, nums):
        sortify = sorted(nums)
        return (bisect_left(sortify, i) for i in nums)
