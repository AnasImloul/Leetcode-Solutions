class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m, n = len(strs), len(strs[0]) # dimensions
        
        @cache 
        def fn(k, prev):
            """Return min deleted columns to make sorted."""
            if k == n: return 0 
            ans = 1 + fn(k+1, prev) # delete kth column
            if prev == -1 or all(strs[i][prev] <= strs[i][k] for i in range(m)): 
                ans = min(ans, fn(k+1, k)) # retain kth column
            return ans 
        
        return fn(0, -1)
