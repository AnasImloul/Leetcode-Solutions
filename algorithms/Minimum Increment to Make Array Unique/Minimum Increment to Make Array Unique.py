class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        c=0
        i=1
        num=[]
        
        while i<len(nums):
            if nums[i]<=nums[i-1]:
                a=nums[i-1]+1
                c+=(a-nums[i])
                nums[i]=a
            i+=1
        return c
    
