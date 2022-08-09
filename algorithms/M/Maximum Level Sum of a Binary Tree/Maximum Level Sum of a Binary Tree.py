 class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        global_max = float('-inf')
        res = -1
        q = deque([root])
        lvl = 1
        while q:
            total = 0
            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                total+=node.val
            if total>global_max:
                res = lvl
                global_max = total
            lvl+=1
        return res
