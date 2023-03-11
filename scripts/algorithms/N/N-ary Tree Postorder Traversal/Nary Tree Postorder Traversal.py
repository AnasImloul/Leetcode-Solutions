class Solution(object):
	def postorder(self, root):
		"""
		:type root: Node
		:rtype: List[int]
		"""
		res=[]
		def bfs(root):
			if root:
				for child in root.children:
					bfs(child)

				res.append(root.val)
		bfs(root)

		return res