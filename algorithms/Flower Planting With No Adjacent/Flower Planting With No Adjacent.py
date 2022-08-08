class Solution:
	def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
		g = defaultdict(list)
		for u,v in paths:
			g[u-1].append(v-1)            
			g[v-1].append(u-1) 
		ans = [0]*n
		for i in range(n):
			c = [1,2,3,4]
			for j in g[i]:
				if ans[j] in c: c.remove(ans[j])
			ans[i] = c.pop()
		return ans