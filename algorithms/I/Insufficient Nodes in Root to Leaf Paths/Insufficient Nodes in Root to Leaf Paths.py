class Solution:
    """
    we can try to solve this problem using depth first traversal
    """
    def dfs(self, root, sum_so_far, limit):
        if root is None:
            return None, 0
        
        x, left  = self.dfs(root.left, sum_so_far + root.val, limit)
        y, right = self.dfs(root.right, sum_so_far + root.val, limit)
        # print('for node= {}, sum_so_far= {}, left= {}, right= {}'.format(root.val, sum_so_far, left, right))
        if root.left is None and root.right is None:
            # it is leaf, left and right should be 0
            if sum_so_far + root.val < limit:
                # node is insufficient
                return None, root.val
            else:
                # node is sufficient
                return root, root.val
        elif root.left is not None and root.right is None:
            root.left = x
            if sum_so_far + root.val + left < limit:
                # node is insufficient
                return None, root.val + left
            else:
                return root, root.val + left
            
        elif root.left is None and root.right is not None:
            root.right = y
            if sum_so_far + root.val + right < limit:
                return None, root.val + right
            else:
                return root, root.val + right
            
        elif root.left is not None and root.right is not None:
            root.left = x
            root.right = y
            if sum_so_far + root.val + left < limit and sum_so_far + root.val + right < limit:
                return None, max(root.val + left, root.val + right)
            elif sum_so_far + root.val + left < limit and sum_so_far + root.val + right > limit:
                return root, root.val + right
            elif sum_so_far + root.val + left > limit and sum_so_far + root.val + right < limit:
                return root, root.val + left
            else:
                return root, max(root.val + left, root.val + right)
        
    def sufficientSubset(self, root: Optional[TreeNode], limit: int) -> Optional[TreeNode]:
        root, _ = self.dfs(root, 0, limit)
        return root
