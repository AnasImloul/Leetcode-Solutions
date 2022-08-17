 class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        adj = defaultdict(list)
        for equation, value in zip(equations, values):
            adj[equation[0]].append((equation[1], value))
            adj[equation[1]].append((equation[0], 1 / value))
        ans = []
        for query in queries:
            self.bfs(query, adj, ans)
        return ans
    
    def bfs(self, query, adj, ans):
        x, y = query
        queue = deque([(x, 1)])
        visited = set([x])
        while queue:
            for _ in range(len(queue)):
                node, r = queue.popleft()
                for neighbor, v in adj[node]:
                    if neighbor == y:
                        ans.append(r * v)
                        return
                    if neighbor not in visited:
                        queue.append((neighbor, r * v))
                        visited.add(neighbor)
        ans.append(-1.0)        
