class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        x, y = entrance
        m, n, infi = len(maze), len(maze[0]), int(1e5)
        reached = lambda p, q: (not p==x or not q==y) and (p==0 or q==0 or p==m-1 or q==n-1)
        @lru_cache(None)
        def dfs(i, j):
            if i<0 or j<0 or i==m or j==n or maze[i][j]=='+':
                return infi
            if reached(i, j):
                return 0
            maze[i][j] = '+'
            ans = 1+min(dfs(i+1, j), dfs(i-1, j), dfs(i, j+1), dfs(i, j-1))
            maze[i][j] = '.'
            return ans
        ans = dfs(x, y)
        return -1 if ans>=infi else ans
