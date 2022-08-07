class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def util(node: TreeNode, sum_array) -> int:
            t = [e - node.val for e in sum_array]
            zeroes = t.count(0)
            if node.left is None and node.right is None:
                return zeroes
            ansl, ansr = 0, 0
            if node.left:
                ansl = util(node.left, t + [targetSum])
            if node.right:
                ansr = util(node.right, t + [targetSum])
            return ansl + ansr + zeroes

        return util(root, [targetSum]) if root is not None else 0
