class Solution:
    def stoneGameVI(self, A, B):
        G  = [a+b for a,b in zip(A,B)]
        G.sort()
        L  = len(A)
        d  = -sum(B) + sum( G[i] for i in range(L-1,-1,-2) )
        return 1 if d>0 else ( -1 if d<0 else 0 )