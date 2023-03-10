class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [-2**32]+nums+[-2**32]
        l,r = 0,len(nums)-1
        while l <=r:
            m = (l+r)//2
			# we find the target:
            if nums[m] > nums[m-1] and nums[m] > nums[m+1]:
                return m -1
            else:
                if nums[m] <nums[m+1]:
                    l = m + 1
                else:
                    r = m - 1
        return -1