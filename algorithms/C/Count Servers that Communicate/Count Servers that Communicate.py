class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        def helper(row,col,count):
            for c in range(len(grid[0])):
                if c == col:
                    continue
                if grid[row][c] == 1:
                    count += 1
                    return count
            for r in range(len(grid)):
                if r == row:
                    continue
                if grid[r][col] == 1:
                    count += 1
                    return count
            return count
        count = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 1:
                    count = helper(row,col,count)
        return count
