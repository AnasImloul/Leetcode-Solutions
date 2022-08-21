# Runtime: 136 ms (Top 91.96%) | Memory: 14.4 MB (Top 28.67%)

class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:

        rows, cols = len(grid), len(grid[0])
        border_color = grid[row][col]
        border = []

        # Check if a node is a border node or not
        def is_border(r, c):
            if r == 0 or r == rows - 1 or c == 0 or c == cols - 1:
                return True

            for dr, dc in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                nr, nc = r + dr, c + dc
                if grid[nr][nc] != border_color:
                    return True
            return False

        def dfs(r, c):
            if r < 0 or c < 0 or r == rows or c == cols or (r, c) in visited or grid[r][c] != border_color:
                return
            visited.add((r, c))

            if is_border(r, c):
                border.append((r, c))

            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        visited = set()
        dfs(row, col)
        for r, c in border:
            grid[r][c] = color
        return grid