class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        inc = [0] * n
        dec = [0] * n
        
#  Longest Increasing Subsequence
        for i in range(1,n):
            for j in range(0,i):
                if nums[i] > nums[j]:
                    inc[i] = max(inc[i], inc[j] + 1)
                
#  Longest Decreasing Subsequence
        for i in range(n-2,-1,-1):
            for j in range(n-1,i,-1):
                if nums[i] > nums[j]:
                    dec[i] = max(dec[i], dec[j] + 1)
        
# Final calculation
        res = 0
        for i in range(0,n):
            if inc[i] > 0 and dec[i] > 0:
                res = max(res, inc[i] + dec[i])
                
# Final conclusion        
        return n - res - 1
