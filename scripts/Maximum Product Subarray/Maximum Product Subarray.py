class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prod=1
        maxprod=-100000000
        for i in range(len(nums)): # traverse from L-R so that we get max 
            prod*=nums[i]
            maxprod=max(maxprod,prod)
            if prod==0:
                prod=1

        prod=1
        for i in range(len(nums)-1,-1,-1): #if 0 or -ve present at starting then find from back
            prod*=nums[i]
            maxprod=max(maxprod,prod)
            if prod==0:
                prod=1

        return maxprod
