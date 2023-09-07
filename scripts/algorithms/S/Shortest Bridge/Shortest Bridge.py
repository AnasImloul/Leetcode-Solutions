# Runtime: 329 ms (Top 84.2%) | Memory: 17.67 MB (Top 84.2%)

class Solution:
    def shortestBridge(self, grid):
        m, n = len(grid), len(grid[0])
        start_i, start_j = next((i, j) for i in range(m) for j in range(n) if grid[i][j])
        
        
        stack = [(start_i, start_j)]
        visited = set(stack)
        while stack:
            i, j = stack.pop()
            visited.add((i, j))  
            for ii, jj in (i-1, j), (i, j-1), (i, j+1), (i+1, j):
                if 0 <= ii < m and 0 <= jj < n and grid[ii][jj] and (ii, jj) not in visited:
                    stack.append((ii, jj))
                    visited.add((ii, jj))
        
        
        ans = 0
        queue = list(visited)
        while queue:
            new_queue = []
            for i, j in queue:
                for ii, jj in (i-1, j), (i, j-1), (i, j+1), (i+1, j):
                    if 0 <= ii < m and 0 <= jj < n and (ii, jj) not in visited:
                        if grid[ii][jj] == 1:
                            return ans
                        new_queue.append((ii, jj))
                        visited.add((ii, jj))
            queue = new_queue
            ans += 1
