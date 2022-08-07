class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res=root.val
        def solving(root):
            if not root:
                return 0
            current=root.val
            sleft,sright=float('-inf'),float('-inf')
            if root.left:
                sleft=solving(root.left)
                if(sleft>=0):
                    current+=sleft
            if root.right:
                sright=solving(root.right)
                if(sright>=0):
                    current+=sright
            if(current>self.res):
                self.res=current
            return max(root.val, root.val+sleft, root.val+sright)
        solving(root)
        return self.res
