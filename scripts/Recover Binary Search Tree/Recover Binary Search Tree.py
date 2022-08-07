class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # strategy: 
        #   - do in-order traversal (yielding node ptr)
        #   - find two values out of order and fix
        
        # in-order traversal
        def dfs(root):
            if root.left is not None:
                yield from dfs(root.left)
            yield root
            if root.right is not None:
                yield from dfs(root.right)
        
        nodes = [node for node in dfs(root)]
        sorted_vals = sorted([n.val for n in nodes])
        
        for n, val in zip(nodes, sorted_vals):
            n.val = val
