# Runtime: 47 ms (Top 88.16%) | Memory: 16.3 MB (Top 23.73%)
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result = 0
        depths = []
        self.handler(root, result, depths)
        return max(depths)

    def handler(self, root, result, depths):
        if root:
            result += 1
            self.handler(root.left, result, depths)
            self.handler(root.right, result, depths)
        else:
            depths.append(result)