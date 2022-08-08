class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def swap(root):
            if root.right is None or (root.left is not None and root.left.val > root.right.val):
                root.left, root.right = root.right, root.left
        
        def equal(root1, root2):
            if root1 is None or root2 is None:
                return root1 is None and root2 is None
            
            swap(root1)
            swap(root2)
            
            return (root1.val == root2.val and
                    equal(root1.left, root2.left) and
                    equal(root1.right, root2.right))
        
        return equal(root1, root2)