class Solution(object):
    def longestConsecutive(self, nums):
        ans=0
        nums=set(nums)
        count=0
        for i in nums:
            if i-1 not in nums:
                j=i
                count=0
                while j in nums:
                    count+=1
                    j+=1
                ans=max(ans,count)            
        return ans
