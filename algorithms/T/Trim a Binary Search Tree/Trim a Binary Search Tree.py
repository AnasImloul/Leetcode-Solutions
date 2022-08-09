class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        
        def trim(node):
			# While current node does not meet the (low, high) requirement trim it
            while node and (node.val < low or node.val > high):
                node = node.right if node.val < low else node.left
            
            if node:
                node.left = trim(node.left)
                node.right = trim(node.right)
            return node

        return trim(root)
