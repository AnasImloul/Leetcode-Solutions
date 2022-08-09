class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        ans, empty = 0, 1
        
        def dfs(grid: List[List[int]], row: int, col: int, count: int, visited) -> None:
            if row >= len(grid) or col >= len(grid[0]) or row < 0 or col < 0 or grid[row][col] == -1:
                return
            nonlocal ans
            if grid[row][col] == 2:
                if empty == count:
                    ans += 1
                return
            if (row, col) not in visited:
                visited.add((row, col))
                dfs(grid, row + 1, col, count + 1, visited)
                dfs(grid, row - 1, col, count + 1, visited)
                dfs(grid, row, col + 1, count + 1, visited)
                dfs(grid, row, col - 1, count + 1, visited)
                visited.remove((row, col))
        
        row, col = 0, 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    row, col = i, j
                elif grid[i][j] == 0:
                    empty += 1
        dfs(grid, row, col, 0, set())
        return ans
