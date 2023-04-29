class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        dist = [[inf]*n for _ in range(n)]
        
        for i, x in enumerate(graph): 
            dist[i][i] = 0
            for ii in x: dist[i][ii] = 1
        
        # floyd-warshall 
        for k in range(n): 
            for i in range(n): 
                for j in range(n): 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        
        @cache 
        def fn(x, mask): 
            if mask == 0: return 0 
            ans = inf 
            for i in range(n): 
                if mask & (1 << i): 
                    ans = min(ans, dist[x][i] + fn(i, mask ^ (1<<i)))
            return ans 
        
        return min(fn(x, (1 << n)-1) for x in range(n))