class Solution:
	def convertBST(self, root: TreeNode) -> TreeNode:
		sum = 0
		
		def sol(root: TreeNode) -> TreeNode:
			nonlocal sum
			if root:
				sol(root.right)
				root.val += sum
				sum = root.val
				sol(root.left)
			return root
		
		return sol(root)