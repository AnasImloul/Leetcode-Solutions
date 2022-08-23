# Runtime: 1787 ms (Top 90.42%) | Memory: 42.7 MB (Top 96.74%)
class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        in_degree=defaultdict(int)
        graph=defaultdict(list)
        latest=[0]*(n+1)
        for u,v in relations:
            graph[u].append(v)
            in_degree[v]+=1
        q=[]
        for i in range(1,n+1):
            if in_degree[i]==0:
                latest[i]=time[i-1]
                q.append(i)
        while q:
            node=q.pop()
            t0=latest[node]
            for nei in graph[node]:
                t=time[nei-1]
                latest[nei]=max(latest[nei],t0+t)
                in_degree[nei]-=1
                if in_degree[nei]==0:
                    q.append(nei)
        return max(latest)
