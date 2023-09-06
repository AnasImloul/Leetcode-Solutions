# Runtime: 1198 ms (Top 36.1%) | Memory: 149.20 MB (Top 27.6%)

class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [[-1]*2 for i in range(len(nums1))]
        
        def solve(prev1, prev2, i, swaped):
            if i >= len(nums1): return 0
            if dp[i][swaped] != -1: return dp[i][swaped]
                        
            ans = 2**31
            
            # No Swap
            if nums1[i] > prev1 and nums2[i] > prev2:
                ans = solve(nums1[i], nums2[i], i+1, 0) 
            
            # Swap
            if nums1[i] > prev2 and nums2[i] > prev1:
                ans = min(ans, 1 + solve(nums2[i], nums1[i], i+1, 1)) 
            
            dp[i][swaped] = ans
            return ans
        
        return solve(-1, -1, 0, 0)  