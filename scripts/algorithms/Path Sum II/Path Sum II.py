class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        def dfs(v, path, pathsum):
            if not v:
                return
            path.append(v.val)
            pathsum += v.val
            if not v.left and not v.right and pathsum == targetSum:
                res.append(path[:])
            dfs(v.left, path, pathsum)
            dfs(v.right, path, pathsum)
            path.pop()
        dfs(root, [], 0)
        return res