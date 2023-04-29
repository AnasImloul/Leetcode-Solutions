class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = dict()
        
        for (n, d), v in zip(equations, values):
            if n not in graph:
                graph[n] = []
            if d not in graph:
                graph[d] = []
                
            graph[n].append((d, v))
            graph[d].append((n, 1/v))
        
        def dfs(node, target, product, visited):
            if n not in graph or d not in graph:
                return -1
            
            if node == target:
                return product
            
            visited.add(node)
            
            for neighbor, quotient in graph[node]:
                if neighbor not in visited:
                    soln = dfs(neighbor, target, product * quotient, visited)
                    if soln != -1:
                        return soln
                    
            return -1
        
        solns = []
        for n, d in queries:
            solns.append(dfs(n, d, 1, set()))
            
        return solns