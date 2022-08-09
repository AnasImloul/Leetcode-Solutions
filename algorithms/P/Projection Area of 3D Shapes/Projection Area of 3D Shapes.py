class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        total = 0
		
        # top
        total += sum([1 for i in grid for j in i if j > 0])
        
		# front
        total +=  sum([max(col) for col in zip(*grid)])
        
		# side
        total +=  sum([max(row) for row in grid])
        
		return total
