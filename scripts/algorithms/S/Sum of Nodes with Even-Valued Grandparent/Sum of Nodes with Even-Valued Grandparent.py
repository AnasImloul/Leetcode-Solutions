class Solution:
	def sumEvenGrandparent(self, root: TreeNode) -> int:

		def dfs(root, p, gp):
			if not root: return 0
			if gp and gp.val%2==0:
				return root.val + dfs(root.left,root,p)+dfs(root.right,root,p)
			return 0 + dfs(root.left,root,p)+dfs(root.right,root,p)

		return dfs(root,None,None)