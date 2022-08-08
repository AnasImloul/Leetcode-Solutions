class Solution:
	def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
		if not preorder:
			return None
		node = preorder.pop(0)
		root = TreeNode(node)
		l = []
		r = []

		for val in preorder:
			if val < node:
				l.append(val)
			else:
				r.append(val)

		root.left = self.bstFromPreorder(l)
		root.right =  self.bstFromPreorder(r)
		return root