class Solution:
	def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
		mxr = [max(i) for i in grid]
		mxc = [0 for _ in range(len(grid[0]))]
		for i in range(len(grid)):
			for j in range(len(grid[0])):
				mxc[j] = max(grid[i][j],mxc[j])
		ans =0 
		for i in range(len(grid)):
			for j in range(len(grid)):
				ans+=(min(mxr[i],mxc[j]) - grid[i][j]) 
		return ans