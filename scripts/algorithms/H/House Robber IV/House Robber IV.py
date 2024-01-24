// Runtime: 603 ms (Top 90.0%) | Memory: 27.60 MB (Top 86.88%)

class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def check(cap):
            count=taken=0
            for x in nums:
                if taken:
                    taken=False
                elif x<=cap:
                    count+=1
                    taken=True
            return count>=k
        l,r=min(nums),max(nums)
        while l<=r:
            mid=l+(r-l)//2
            if check(mid):
                res=mid
                r=mid-1
            else:
                l=mid+1
        return res       
