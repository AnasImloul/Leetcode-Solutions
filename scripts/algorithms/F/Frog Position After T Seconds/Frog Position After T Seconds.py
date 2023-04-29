class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        adj = [[] for i in range(n)]
        for u,v in edges:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        def f(u,p,tt):
            if(u==target-1): return tt==0 or len(adj[u])==(p>=0)
            if(tt==0): return 0
            res = 0
            for v in adj[u]:
                if(p==v): continue
                res = max(res,(1/(len(adj[u])-(p!=-1)))*f(v,u,tt-1))
            return res
        return f(0,-1,t)
            
            
        