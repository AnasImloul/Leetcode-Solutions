class Solution:
    def helper(self,nums,m):
        Sum = 0
        for n in nums:
            Sum += math.ceil(n/m)
        return Sum
    
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        l,r = 1, max(nums)
        while l < r:
            mid = (l+r)//2
            Sum = self.helper(nums,mid)
            if Sum > threshold:
                l = mid + 1
            else:
                r = mid     
        return r
