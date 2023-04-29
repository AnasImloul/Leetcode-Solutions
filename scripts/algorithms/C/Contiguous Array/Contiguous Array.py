class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        # dictionary
        prefixSum = {0: -1}
        total = 0
        maxlength = 0
        
        for index, value in enumerate(nums):
            if value == 0:
                total -= 1
            else:
                total += 1
            if total not in prefixSum.keys():
                prefixSum[total] = index
            else:
                maxlength = max(maxlength, index-prefixSum[total])        
        return maxlength
