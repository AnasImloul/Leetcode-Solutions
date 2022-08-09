class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        
        x_dir = [2, 1, -1, -2, -2, -1, 1, 2]
        y_dir = [1, 2, 2, 1, -1, -2, -2, -1]
        
        cache = {}
        
        def kMoves(i, j, moves):
            if i >= n or j >= n or i < 0 or j < 0:
                return 0
            
            if moves == k:
                return 1
            
            if (i, j, moves) in cache:
                return cache[(i, j, moves)]
            
            totMoves = 0
            for ind in range(8):
                totMoves += kMoves(i+x_dir[ind], j+y_dir[ind], moves+1)*(1/8)
            
            cache[(i, j, moves)] = totMoves
            return totMoves
        
        return kMoves(row, column, 0)
