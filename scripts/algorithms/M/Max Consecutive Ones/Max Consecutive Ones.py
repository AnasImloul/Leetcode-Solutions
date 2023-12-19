// Runtime: 297 ms (Top 70.36%) | Memory: 16.60 MB (Top 19.05%)

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        
        count = maxCount = 0
        
        for i in range(len(nums)):
            if nums[i] == 1:
                count += 1
            else:
                maxCount = max(count, maxCount)
                count = 0
                
        return max(count, maxCount)
