from queue import Queue
from typing import List


class Solution:
    def __init__(self):
        self.directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        [rows, cols] = [len(grid), len(grid[0])]

        ans = 0
        visited: List[List[bool]] = [[False for _ in range(cols)] for _ in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                if not visited[i][j] and grid[i][j]:
                    res = self.dfs(grid, visited, i, j)
                    ans = res if res > ans else ans 

        return ans

    def dfs(self, grid: List[List[int]], visited: List[List[bool]], startRow: int, startCol: int) -> int:
        [rows, cols] = [len(grid), len(grid[0])]
        
        fields = 1
        q = Queue()

        q.put([startRow, startCol])
        visited[startRow][startCol] = True

        while not q.empty():
            [row, col] = q.get()
            for d in self.directions:
                newRow = row + d[0]
                newCol = col + d[1]
                if newRow >= 0 and newRow < rows and newCol >= 0 and newCol < cols and not visited[newRow][newCol] and grid[newRow][newCol]:
                    visited[newRow][newCol] = True
                    fields += 1
                    q.put([newRow, newCol])
        
        return fields
