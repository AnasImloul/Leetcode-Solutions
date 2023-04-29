class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        def dfs(node, level, result):
            if not node:
                return
            if level >= len(result):
                result.append([])
            result[level].append(node.val)
            dfs(node.left, level+1, result)
            dfs(node.right, level+1, result)
        result = []
        dfs(root, 0, result)
        return result[::-1]