class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(node,x):
            if node is None:
                return x
            x = dfs(node.right,x)
            x += node.val
            node.val = x
            x = dfs(node.left,x)
            return x
        dfs(root,0)
        return root
