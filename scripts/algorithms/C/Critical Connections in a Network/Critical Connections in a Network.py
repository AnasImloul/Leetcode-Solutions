class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        
        dic = collections.defaultdict(list)
        for c in connections:
            u, v = c
            dic[u].append(v)
            dic[v].append(u)
            
        
        timer = 0
        
        depth, lowest, parent, visited = [float("inf")]*n, [float("inf")]*n, [float("inf")]*n, [False]*n
        res = []
        
        def find(u):
            
            nonlocal timer
            
            visited[u] = True
            depth[u], lowest[u] = timer, timer
            timer += 1
            
            for v in dic[u]:   
                
                if not visited[v]:
                    parent[v] = u
                    find(v)
                    if lowest[v]>depth[u]:
                        res.append([u,v])
                
                if parent[u]!=v:
                    lowest[u] = min(lowest[u], lowest[v])
                
        find(0)
        return res
        