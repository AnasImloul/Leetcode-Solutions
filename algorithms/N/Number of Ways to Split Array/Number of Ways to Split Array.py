class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        prefix_sum = [nums[0]]
        n = len(nums)
        for i in range(1, n):
            prefix_sum.append(nums[i] + prefix_sum[-1]) 
        
        count = 0
        for i in range(n-1):
            if prefix_sum[i] >= prefix_sum[n-1] - prefix_sum[i]:
                count += 1
        return count
