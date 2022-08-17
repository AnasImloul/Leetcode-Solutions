class Solution:
	def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:

		parent=[[] for i in range(n)]
		for i in edges:
			parent[i[1]].append(i[0])
		ans=[]
		for i in range(n):
			if len(parent[i])==0:
				ans.append(i)
		return ans
