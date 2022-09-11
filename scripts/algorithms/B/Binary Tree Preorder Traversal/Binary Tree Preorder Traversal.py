# Runtime: 58 ms (Top 23.56%) | Memory: 13.9 MB (Top 60.28%)
from collections import deque
from typing import List, Optional

class Solution:
    """
    Time: O(n)
    Memory: O(n)
    """

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        queue = deque([root])
        preorder = []

        while queue:
            node = queue.pop()
            preorder.append(node.val)

            if node.right is not None:
                queue.append(node.right)
            if node.left is not None:
                queue.append(node.left)

        return preorder

class Solution:
    """
    Time: O(n)
    Memory: O(n)
    """

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return list(self.preorder_generator(root))

    @classmethod
    def preorder_generator(cls, tree: Optional[TreeNode]):
        if tree is not None:
            yield tree.val
            yield from cls.preorder_generator(tree.left)
            yield from cls.preorder_generator(tree.right)