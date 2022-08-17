class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        count=nums[0]
        final=nums[0]
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                count+=nums[i]
            else:
                count=nums[i]
            final=max(final,count)
        return final
