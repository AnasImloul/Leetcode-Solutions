class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        level = [root] if root else []
        res = []
        while level:
            nxt_level = []
            res.append([])
            level.reverse()
            while level:
                v = level.pop()
                res[-1].append(v.val)
                if v.left: nxt_level.append(v.left)
                if v.right: nxt_level.append(v.right)
            level = nxt_level
        return res[::-1]