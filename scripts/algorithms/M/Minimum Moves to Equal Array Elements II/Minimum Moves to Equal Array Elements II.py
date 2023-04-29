class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        
        n=len(nums)
        nums.sort()
        
        if n%2==1:
            median=nums[n//2]
        else:
            median = (nums[n//2 - 1] + nums[n//2]) // 2
        
        ans=0
        
        for val in nums:
            ans+=abs(val-median)
        
        return ans
        
