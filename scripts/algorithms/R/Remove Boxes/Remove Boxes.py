class Solution:
    def removeBoxes(self, B):
        
        @lru_cache(None)
        def dp(i, j, k):
            if i > j: return 0
            indx = [m for m in range(i+1, j+1) if B[m] == B[i]]
            ans = (k+1)**2 + dp(i+1, j, 0)
            return max([ans] + [dp(i+1, m-1, 0) + dp(m, j, k+1) for m in indx])   
            
        return dp(0, len(B)-1, 0)