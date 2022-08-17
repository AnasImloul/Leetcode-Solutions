class Solution:
    def isSelfCrossing(self, x):
        n = len(x)
        if n < 4: return False
        for i in range(3, n):
            if x[i] >= x[i-2] and x[i-1] <= x[i-3]: return True
            if i >= 4 and x[i-1]==x[i-3] and x[i]+x[i-4]>=x[i-2]: return True
            if i >= 5 and 0<=x[i-2]-x[i-4]<=x[i] and 0<=x[i-3]-x[i-1]<=x[i-5]: return True
        return False
        
