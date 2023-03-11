from collections import deque
from typing import List

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        # Initialize a queue and a 2D array to store the distances
        queue = deque()
        dist = [[float('inf') for _ in range(len(mat[0]))] for _ in range(len(mat))]
        
        # Add all the 0s in the matrix to the queue and set their distance to 0
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 0:
                    queue.append((i, j))
                    dist[i][j] = 0
        
        # Perform breadth-first search
        while queue:
            i, j = queue.popleft()
            for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                if 0 <= x < len(mat) and 0 <= y < len(mat[0]) and dist[x][y] > dist[i][j] + 1:
                    dist[x][y] = dist[i][j] + 1
                    queue.append((x, y))
        
        return dist
