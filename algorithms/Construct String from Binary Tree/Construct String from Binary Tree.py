class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if root.left and root.right:
            return str(root.val) + "("+self.tree2str(root.left)+")("+self.tree2str(root.right)+")"
        if root.left and not root.right:
            return str(root.val)+"("+self.tree2str(root.left)+")"
        if not root.left and root.right:
            return str(root.val)+"()("+self.tree2str(root.right)+")"
        if not root.left and not root.right:
            return str(root.val)
