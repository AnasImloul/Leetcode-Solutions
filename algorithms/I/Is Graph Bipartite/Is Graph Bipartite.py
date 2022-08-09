class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        v = len(graph)
        color = [-1]*v
        color[0] = 1
        def helper(src, q):
            q.append(src)
            
            while q:
                node = q.pop(0)
                
                for j in graph[node]:
                    if color[j] == -1:
                        color[j] = 1 - color[node]
                        q.append(j)
                    elif color[node] == color[j]:
                        return False
            return True
            
        for i in range(v):
            if not helper(i, []):
                return False
        return True
	```