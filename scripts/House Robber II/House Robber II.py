class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        def helper(nums):
            one, two = 0, 0
            for i in nums:
                temp = max(i + one, two)
                one = two
                two = temp
            return two
        
        return max(helper(nums[:-1]), helper(nums[1:]))
