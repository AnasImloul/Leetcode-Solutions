from typing import List, Optional


class Solution:
	"""
	Time:   O(n)
	Memory: O(n)
	"""

	def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
		if root is None:
			return []

		postorder = []
		stack = [root]

		while stack:
			node = stack.pop()
			postorder.append(node.val)
			if node.left is not None:
				stack.append(node.left)
			if node.right is not None:
				stack.append(node.right)

		return postorder[::-1]


class Solution:
	"""
	Time:   O(n)
	Memory: O(n)
	"""

	def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
		return list(self.postorder_generator(root))

	@classmethod
	def postorder_generator(cls, tree: Optional[TreeNode]):
		if tree is not None:
			yield from cls.postorder_generator(tree.left)
			yield from cls.postorder_generator(tree.right)
			yield tree.val