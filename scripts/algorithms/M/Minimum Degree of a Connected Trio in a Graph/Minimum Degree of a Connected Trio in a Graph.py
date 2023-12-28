// Runtime: 4822 ms (Top 24.41%) | Memory: 38.50 MB (Top 62.2%)

class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        graph = [[False]*n for _ in range(n)]
        degree = [0]*n
        
        for u, v in edges: 
            graph[u-1][v-1] = graph[v-1][u-1] = True
            degree[u-1] += 1
            degree[v-1] += 1
        
        ans = inf
        for i in range(n): 
            for j in range(i+1, n):
                if graph[i][j]: 
                    for k in range(j+1, n):
                        if graph[j][k] and graph[k][i]: 
                            ans = min(ans, degree[i] + degree[j] + degree[k] - 6)
        return ans if ans < inf else -1
