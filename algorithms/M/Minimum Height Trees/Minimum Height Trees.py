class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n==0:
            return []
        if n==1:return [0]
        adj=[[] for i in range (n)]
        degree=[0]*n
        for i in edges:
            adj[i[0]].append(i[1])
            adj[i[1]].append(i[0])
            degree[i[0]]+=1
            degree[i[1]]+=1
            
        print(adj)
        q=[]
        for i in range(n):
            if degree[i]==1:
                q.append(i)
                
        while n>2:
            size=len(q)
            n-=size
            while size>0:
                v=q.pop(0)
                for i in adj[v]:
                    degree[i]-=1
                    if degree[i]==1:
                        q.append(i)
                size-=1
        return q
                
            
        
