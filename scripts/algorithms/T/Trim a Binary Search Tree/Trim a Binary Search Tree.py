// Runtime: 58 ms (Top 27.96%) | Memory: 20.40 MB (Top 38.8%)

class Solution:
	def trimBST(self, root: TreeNode, low: int, high: int) -> TreeNode:
		if not root: return root
		if root.val < low: return self.trimBST(root.right, low, high)
		if root.val > high: return self.trimBST(root.left, low, high)
		root.left = self.trimBST(root.left, low, high)
		root.right = self.trimBST(root.right, low, high)
		return root