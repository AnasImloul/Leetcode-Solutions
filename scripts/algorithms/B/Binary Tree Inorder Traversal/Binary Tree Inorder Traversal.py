from typing import List, Optional


class Solution:
	"""
	Time:   O(n)
	Memory: O(n)
	"""

	def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
		inorder = []
		stack = []

		while stack or root is not None:
			if root:
				stack.append(root)
				root = root.left
			else:
				node = stack.pop()
				inorder.append(node.val)
				root = node.right

		return inorder


class Solution:
	"""
	Time:   O(n)
	Memory: O(n)
	"""

	def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
		return list(self.inorder_generator(root))

	@classmethod
	def inorder_generator(cls, tree: Optional[TreeNode]):
		if tree is not None:
			yield from cls.inorder_generator(tree.left)
			yield tree.val
			yield from cls.inorder_generator(tree.right)
