class Graph:
    
    def __init__(self, colors):
        self.V = len(colors)
        self.adj = [[] for _ in range(self.V)]
        self.reset()
        
    def reset(self):
        self.visited = [False] * self.V
        self.recursion = [False] * self.V
        self.stack = []
        
    def addEdges(self, edges: List[List[int]]):
        for u,v in edges:
            self.addEdge(u, v)
        
    def addEdge(self, u, v):
        self.adj[u].append(v)        
        
    def DFS(self, u):
        if self.recursion[u]:
            raise ValueError("Cycled Detected")

        if self.visited[u]:
            return

        self.visited[u] = True
        self.recursion[u] = True

        for v in self.adj[u]:
            self.DFS(v)
            
        self.stack.append(u)
            
        self.recursion[u] = False
    
    def getTopologicalSortOrder(self):        
        self.reset()
        
        for u in range(self.V):
            self.DFS(u)
        
        return self.stack[::-1]
    
    def isConnected(self, u, v):
        return self.adj[u].index(v) >= 0
    
    def getAdjs(self, u):
        return self.adj[u]
        
        

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
                             
        g = Graph(colors)
        g.addEdges(edges)
        
        try:
            order = g.getTopologicalSortOrder()

            result, dp = 0, [[0]*26 for _ in range(len(order)+1)]
            for i in range(len(order)-1, -1, -1):            
                u = order[i]
                # we are storing the max colours possible for all paths from this node      
                for v in g.getAdjs(u):
                    for k in range(26):
                        dp[u][k] = max(dp[u][k], dp[v][k])

                c = ord(colors[u])-97
                dp[u][c] += 1

                result = max(result, max(dp[u]))

            return result        
        except:
            return -1
        
