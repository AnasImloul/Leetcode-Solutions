class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        
        @cache
        def fn(prev, i, j, intro, extro): 
            """Return max grid happiness at (i, j)."""
            if i == m: return 0 # no more position
            if j == n: return fn(prev, i+1, 0, intro, extro)
            if intro == extro == 0: return 0 
            
            prev0 = prev[:j] + (0,) + prev[j+1:]
            ans = fn(prev0, i, j+1, intro, extro)
            if intro: 
                val = 120 
                if i and prev[j]: # neighbor from above 
                    val -= 30 
                    if prev[j] == 1: val -= 30 
                    else: val += 20 
                if j and prev[j-1]: # neighbor from left 
                    val -= 30 
                    if prev[j-1] == 1: val -= 30 
                    else: val += 20 
                prev0 = prev[:j] + (1,) + prev[j+1:]
                ans = max(ans, val + fn(prev0, i, j+1, intro-1, extro))
            if extro: 
                val = 40 
                if i and prev[j]: 
                    val += 20 
                    if prev[j] == 1: val -= 30 
                    else: val += 20 
                if j and prev[j-1]: 
                    val += 20 
                    if prev[j-1] == 1: val -= 30 
                    else: val += 20 
                prev0 = prev[:j] + (2,) + prev[j+1:]
                ans = max(ans, val + fn(prev0, i, j+1, intro, extro-1))
            return ans 
        
        return fn((0,)*n, 0, 0, introvertsCount, extrovertsCount)