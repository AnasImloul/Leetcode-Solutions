class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        n = len(nums)
        m = len(multipliers)
        
        @lru_cache(None)
        #To Save Computed Result
        
        def X(i, left):
            
            if i==m:
                return 0
            
            return max  (   (multipliers[i] * nums[left])          + X(i + 1, left + 1), 
                            (multipliers[i] * nums[n-1-(i-left)])  + X(i + 1, left)       )        
                
        #Start from Zero operations
        return X(0,0)
