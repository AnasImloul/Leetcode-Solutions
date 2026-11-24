# Runtime: 126 ms (Top 36.89%) | Memory: 50.50 MB (Top 50.49%)

class Solution:    
    def maximumScoreAfterOperations(self, edges: 
                       List[List[int]], values: List[int]) -> int:

        def dfs(node: int, par = -1, sm = 0) -> int:

            if node and g[node] == [par]: return values[node]

            for child in g[node]:
                if child != par: sm += dfs(child, node)

            return min(sm, values[node])


        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)

        return sum(values) - dfs(0)
