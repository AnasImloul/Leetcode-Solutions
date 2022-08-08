class Solution(object):
    def maxValueAfterReverse(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # basic idea without fancy stuff  
        # 1. https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/discuss/489929/O(n)-time-O(1)-space.-In-depth-Explanation
        # 2. https://code.dennyzhang.com/reverse-subarray-to-maximize-array-value
        
        # This can be done in three steps each step taking O(N) time
        
        res, n = 0, len(nums)
        
        # Step 1: Assume that no subarray is reversed and so the sum would just accumulate over all the abs differences
        for index in range(1, n):
            res += abs(nums[index] - nums[index - 1])
        
        # Step 2: Reversing the left or the right half so basically this idea stems from prefix array type question where in which we have the sum upto ith index but then to get at a specific index we substract extra sum, following from that idea. Or refer to the reference 1
        
        diff = 0
        for index in range(n):
            
            # reversing from 0th index to current
            if index + 1 < n:
                diff = max(diff, abs(nums[index + 1] - nums[0]) - abs(nums[index + 1] - nums[index])) # diff between 0 and curr - diff curr and curr + 1
            
            # reversing from current to last index n - 1
            if index > 0:
                diff = max(diff, abs(nums[index - 1] - nums[n - 1]) - abs(nums[index - 1] - nums[index]))
                
        
        # Step 3: We still need to check the middle reverse part, we can do this using the min max trick
        low_number, high_number = float("inf"), float("-inf")
        
        for index in range(n - 1):
            
            low_number = min(low_number, max(nums[index], nums[index + 1])) # min of low and the max of the current and next number
            high_number = max(high_number, min(nums[index], nums[index + 1]))
        
			diff = max(diff, 2 * (high_number - low_number)) # This is explained in ref 1
        
        return res + diff
            
        
