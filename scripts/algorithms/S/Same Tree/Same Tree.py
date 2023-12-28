// Runtime: 43 ms (Top 21.7%) | Memory: 17.30 MB (Top 8.84%)

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack = [[p,q]]
        while stack:
            p,q = stack.pop()
            if not p and not q:					#(1)
                continue
            elif p and q and p.val == q.val:	#(2)
                stack.append([p.left, q.left])
                stack.append([p.right, q.right])
            else:								#(3)
                return False
        return True
