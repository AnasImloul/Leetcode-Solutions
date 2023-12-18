// Runtime: 303 ms (Top 21.43%) | Memory: 21.30 MB (Top 33.04%)

class Solution:
    def canChange(self, A: str, B: str) -> bool:
        P = lambda c    :  c != '_'
        I = lambda s,x  :  [i for i,c in enumerate(s) if c==x]
        G = lambda d,p  :  all( p(x,y) for x,y in zip( I(A,d), I(B,d) ) )
        S = lambda      :  [*filter(P,A)] == [*filter(P,B)]
        return S() and G('L', ge) and G('R', le)
		#      1.          2.             3.
