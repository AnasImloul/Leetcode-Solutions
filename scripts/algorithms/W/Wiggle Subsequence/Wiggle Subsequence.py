# Runtime: 47 ms (Top 48.8%) | Memory: 16.22 MB (Top 87.1%)

#####################################################################################################################
# Problem:  Wiggle Subsequence
# Solution : Dynamic Programming
# Time Complexity : O(n) 
# Space Complexity : O(1)
#####################################################################################################################

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        
        positive, negative = 1, 1
        
        if len(nums) < 2:
            return len(nums)
        
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                positive = negative + 1
            elif nums[i] < nums[i - 1]:
                negative = positive + 1
                
        return max(positive, negative)