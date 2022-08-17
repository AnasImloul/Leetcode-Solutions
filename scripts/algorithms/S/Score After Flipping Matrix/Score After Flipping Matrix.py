class Solution:

    def calcScore(self):
        score = 0
        
        for row in self.grid:
            for i in range(self.width):
                score += row[i] * (2 ** (self.width - i - 1))
        return score
    
    def flipRow(self, row):
        for i in range(self.width):
            self.grid[row][i] = int(not self.grid[row][i])
        
    def flipCol(self, col):
        for i in range(self.height):
            self.grid[i][col] = int(not self.grid[i][col])
            
    def colSum(self, col):
        total = 0
        
        for i in range(self.height):
            total += self.grid[i][col]
            
        return total
    
    def matrixScore(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.height = len(grid)
        self.width = len(grid[0])
        
        for r in range(self.height):
            if not self.grid[r][0]:
                if not self.grid[r][0]:
                    self.flipRow(r)
                    
        for c in range(1, self.width):
            colSum = self.colSum(c)
            
            if colSum < ceil(self.height/2):
                self.flipCol(c)
            
        return self.calcScore()
        
