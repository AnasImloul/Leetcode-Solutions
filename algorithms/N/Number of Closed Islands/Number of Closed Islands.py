class Solution:
    '''主函数：计算封闭岛屿的数量'''
    def closedIsland(self, grid: List[List[int]]) -> int:
        result = 0
        m, n = len(grid), len(grid[0])
        self.direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        
        # 遍历 grid，处理边缘陆地
        for j in range(n):
            self.dfs(grid, 0, j)
            self.dfs(grid, m - 1, j)
        for i in range(m):
            self.dfs(grid, i, 0)
            self.dfs(grid, i, n - 1)
        
        # 剩下都是封闭岛屿，遍历找结果
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    result += 1
                    self.dfs(grid, i, j)
        return result
    
    '''从 (i, j) 开始，将与之相邻的陆地都变成海水'''
    def dfs(self, grid, i, j):
        m, n = len(grid), len(grid[0])
        # 超出索引边界
        if i < 0 or j < 0 or i >= m or j >= n:
            return
        # 已经是海水了
        if grid[i][j] == 1:
            return
        # 变成海水
        grid[i][j] = 1
        for d in self.direction:
            x = i + d[0]
            y = j + d[1]
            self.dfs(grid, x, y)
