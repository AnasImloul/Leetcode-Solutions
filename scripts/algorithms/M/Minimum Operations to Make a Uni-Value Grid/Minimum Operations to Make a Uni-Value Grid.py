
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        
        m = len(grid)
        n = len(grid[0])
		
		# handle the edge case
        if m==1 and n==1: return 0
		
		# transform grid to array, easier to operate
        arr = [] 
        for i in range(m):
            arr+=grid[i]
        
        arr.sort()
        
		# the median is arr[len(arr)//2] when len(arr) is odd
		# or may be arr[len(arr)//2] and arr[len(arr)//2-1] when len(arr) is even.
        cand1 = arr[len(arr)//2]
        cand2 = arr[len(arr)//2-1]
        
        return min(
            self.get_num_operations_to_target(grid, cand1, x),
            self.get_num_operations_to_target(grid, cand2, x)
        )
        
        
    def get_num_operations_to_target(self, grid, target,x):
		"""Get the total number of operations to transform all grid elements to the target value."""
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if abs(grid[i][j]-target)%x!=0:
                    return -1
                else:
                    ans+=abs(grid[i][j]-target)//x

        return ans
                
