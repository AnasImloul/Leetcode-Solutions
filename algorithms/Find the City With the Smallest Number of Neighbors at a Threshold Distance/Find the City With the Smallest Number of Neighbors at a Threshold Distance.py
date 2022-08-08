class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:

        matrix = [[float('inf')] * n for _ in range(n)]
        
        # initializing the matrix
        for u, v, w in edges:
            matrix[u][v] = w
            matrix[v][u] = w

        for u in range(n):
            matrix[u][u] = 0
        
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if matrix[i][j] > matrix[i][k] + matrix[k][j]:
                        matrix[i][j] = matrix[i][k] + matrix[k][j]
        
        # counting reachable cities(neighbor) for every single city 
        res = [0] * n
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if 0 < matrix[i][j] <= distanceThreshold:
                    res[j] += 1
        return [i for i, x in enumerate(res) if x == min(res)][-1]
