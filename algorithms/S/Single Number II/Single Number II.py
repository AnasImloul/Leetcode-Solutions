import math
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        [0,-1,1,0]
        
        [2,2,3,2]
        [2,2,3,2]
        [2,2,3,2]
        10   10   11  10
        """
        total = sum(nums)
        
        uniqueTotals = set()
        while nums:
            uniqueTotals.add(nums.pop())
        return (sum(uniqueTotals)*3 - total)/2
