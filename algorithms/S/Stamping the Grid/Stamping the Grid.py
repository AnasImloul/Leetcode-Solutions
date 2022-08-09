class Solution:
    def prefix_sum(self, grid: List[List[int]]) -> List[List[int]]:
            ps = [[grid[row][col] for col in range(len(grid[0]))]for row in range(len(grid))]
            
            for row in range(len(grid)):
                for col in range(1, len(grid[0])):
                    ps[row][col] = ps[row][col-1] + grid[row][col]
            
            for row in range(1, len(grid)):
                for col in range(len(grid[0])):
                    ps[row][col] = ps[row-1][col] + ps[row][col]
            
            return ps
			
    def sumRegion(self, ps, row1: int, col1: int, row2: int, col2: int) -> int:
            ans = 0
            if row1 == 0 and col1 == 0:
                ans = ps[row2][col2]
            elif row1 == 0:
                ans = ps[row2][col2] - ps[row2][col1-1]
            elif col1 == 0:
                ans = ps[row2][col2] - ps[row1-1][col2]
            else:
                ans = ps[row2][col2] - ps[row1-1][col2] - ps[row2][col1-1] + ps[row1-1][col1-1]
            return ans

    def possibleToStamp(self, grid: List[List[int]], stampHeight: int, stampWidth: int) -> bool:
        diff = [[0 for col in range(len(grid[0])+1)]for row in range(len(grid)+1)]
        
        ps = self.prefix_sum(grid)
        cover = 0
        
        for row in range(len(grid)-(stampHeight-1)):
            for col in range(len(grid[0])-(stampWidth-1)):
                sub_sum = self.sumRegion(ps, row, col, row+stampHeight-1, col+stampWidth-1)
                if sub_sum == 0:
                    diff[row][col] += 1
                    diff[row][col+stampWidth] -= 1
                    diff[row+stampHeight][col] -= 1
                    diff[row+stampHeight][col+stampWidth] = 1
        pref_diff = self.prefix_sum(diff)
        m, n = len(grid), len(grid[0])
        
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 0 and pref_diff[row][col] == 0: return False 
        
        return True
