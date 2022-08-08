class Solution:
	def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
		# if not root: return True
		def node_count(root):
			if not root: return 0
			return 1 + node_count(root.left) + node_count(root.right)

		def isCBT(root,i,count):
			if not root: return True
			if i>=count: return False
			return isCBT(root.left,2*i+1,count) and isCBT(root.right,2*i+2,count)


		return isCBT(root,0,node_count(root))