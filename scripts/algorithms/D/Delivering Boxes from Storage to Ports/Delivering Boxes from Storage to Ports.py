// Runtime: 2593 ms (Top 36.11%) | Memory: 66.70 MB (Top 22.22%)

from sortedcontainers import SortedList as MonoQueue
class Solution:
    def boxDelivering(self, A, __, B, W):
        n = len(A)
        def slidingWindow():
            l=0
            cW = 0
            for r in range(n):
                cW+=A[r][1]
                while cW>W or r-l+1>B:
                    cW-=A[l][1]
                    l+=1
                yield l,r
        Seg=MonoQueue(key=lambda t:t[1])
        addAll = 0
        olddp = 0
        for l,r in slidingWindow():
            if r!=0:
                addAll+= ( A[r][0]!=A[r-1][0] )
            Seg.add((r, olddp-addAll+2))
            while Seg[0][0]<l:
                Seg.pop(0)
            olddp = Seg[0][1]+addAll
        return olddp
