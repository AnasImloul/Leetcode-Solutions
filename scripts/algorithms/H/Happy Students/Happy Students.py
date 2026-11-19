# Runtime: 48 ms (Top 63.92%) | Memory: 29.60 MB (Top 17.53%)

class Solution:
    def countWays(self, nums: List[int]) -> int:
        n=len(nums)
        res=0
        nums.sort()
        if nums[0]>0:
            res+=1
        if nums[-1]<n:
            res+=1

        for i in range(n-1):
            s = i+1
            if nums[i]<s and nums[i+1]>s:
                res+=1
        return res
