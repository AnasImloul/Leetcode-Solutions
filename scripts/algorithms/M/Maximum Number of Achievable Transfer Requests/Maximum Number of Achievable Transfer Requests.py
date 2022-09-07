# Runtime: 4533 ms (Top 17.14%) | Memory: 13.9 MB (Top 48.57%)
class Solution:
    def maximumRequests(self, n: int, r: List[List[int]]) -> int:
        k=len(r)
        deg=[0 for i in range(n)]

        def check(i,res,s):
            if i==k:
                #print(deg,s)
                if max(deg)==min(deg)==0:
                    res[0]=max(res[0],s)
                return

            u,v=r[i]
            deg[u]-=1
            deg[v]+=1
            check(i+1,res,s+1)
            deg[u]+=1
            deg[v]-=1
            check(i+1,res,s)
        res=[0]
        check(0,res,0)
        return res[0]
