class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        i=0
        pos=0
        l=len(nums)
        ans=0
        while i<l:
            if pos+nums[i] < 1:
                ans+=abs(pos+nums[i])+1
                pos=1
            else:
                pos+=nums[i]
            i+=1
        return max(ans,1)
