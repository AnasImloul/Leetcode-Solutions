# Runtime: 113 ms (Top 26.14%) | Memory: 31.70 MB (Top 58.39%)

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx,ans,l,r,n=max(nums),0,0,0,len(nums)
        while r<n:
            k-= nums[r]==mx
            r+=1
            while k==0:
                k+=nums[l]==mx
                l+=1
            ans+=l
        return ans;
