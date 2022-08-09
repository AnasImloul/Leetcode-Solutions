class Solution:
	max_path=0
	def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
		self.dfs(root);
		return self.max_path

	def dfs(self,root):
		if root is None:return 0
		left=self.dfs(root.left)
		right=self.dfs(root.right)

		if root.left  and  root.left.val == root.val:
			leftPath=left+1
		else:
			leftPath=0

		if root.right and  root.right.val == root.val:
			rightPath=right+1
		else:
			rightPath=0

		self.max_path = max(self.max_path, leftPath + rightPath)
		return max(leftPath, rightPath)
