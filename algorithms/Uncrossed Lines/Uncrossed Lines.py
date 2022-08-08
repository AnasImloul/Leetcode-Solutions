class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        
        @lru_cache(None)
        def dp(a,b):
            if a>=len(nums1) or b>=len(nums2): return 0
            if nums1[a]==nums2[b]: return 1+dp(a+1,b+1)
            else: return max(dp(a+1,b),dp(a,b+1))
        
        return dp(0,0)
