# Runtime: 755 ms (Top 91.19%) | Memory: 25.4 MB (Top 98.78%)
class Solution(object):
    def maxProbability(self, n, edges, succProb, start, end):
        adj=[[] for i in range(n)]
        dist=[sys.maxsize for i in range(n)]
        heap=[]
        c=0
        for i,j in edges:
            adj[i].append([j,succProb[c]])
            adj[j].append([i,succProb[c]])
            c+=1
        heapq.heappush(heap,[-1.0,start])
        dist[start]=1
        while(heap):
            prob,u=heapq.heappop(heap)
            for v,w in adj[u]:
                if(dist[v]>-abs(w*prob)):
                    dist[v]=-abs(w*prob)
                    heapq.heappush(heap,[dist[v],v])
        if(sys.maxsize==dist[end]):
            return 0.00000
        else:
            return -dist[end]