class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        m, n = len(points), len(points[0])
        
        for i in range(m - 1):
            for j in range(1, n):
                points[i][j] = max(points[i][j], points[i][j - 1] - 1)
            
            for j in range(n - 2, -1, -1):
                points[i][j] = max(points[i][j], points[i][j + 1] - 1)
            
            for j in range(n):
                points[i + 1][j] += points[i][j]
        
        return max(points[m - 1])