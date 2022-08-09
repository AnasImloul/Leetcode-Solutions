'''
from collections import deque
class Solution:
	def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
		L=len(grid)
		def generate_next_state(i,j):
			return [(i+1,j),(i-1,j),(i,j+1),(i,j-1),(i+1,j-1),(i+1,j+1),(i-1,j-1),(i-1,j+1)]
		def valid_state(states):
			res=[]
			for (i,j) in states:
				if i>L-1:continue
				if i<0:continue
				if j<0:continue
				if j>L-1:continue
				if grid[i][j]==0:
					res.append((i,j))
			return res
		queue=deque([(0,0)])
		res=1
		while queue:
			for _ in range(len(queue)):
				i,j=queue.popleft()
				val=grid[i][j]
				grid[i][j]=1
				if not val:
					if i==L-1 and j==L-1:
						return res

					next_state=valid_state(generate_next_state(i,j))
					for (ki,kj) in next_state:
						queue.append((ki,kj))
			res+=1
		return -1
                
        
        
    
'''