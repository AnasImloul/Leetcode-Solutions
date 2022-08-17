class Solution:
    def minNumberOperations(self, nums: List[int]) -> int:
        res=nums[0]
        prev=nums[0]
        for i in range(1,len(nums)):
            res += max(0,nums[i]-prev)
            prev=nums[i]
        return res
