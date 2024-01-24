// Runtime: 32 ms (Top 89.57%) | Memory: 16.70 MB (Top 53.69%)

class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        queue = deque([(root1, root2)])
        while queue:
            node1, node2 = queue.pop()
            if (not node1) and (not node2):
                continue
            elif (not node1) or (not node2) or (node1.val != node2.val):
                return False
            L1, R1, L2, R2 = node1.left, node1.right, node2.left, node2.right
            if (L1 and L2 and L1.val == L2.val) or (R1 and R2 and R1.val == R2.val):
                queue.append((L1, L2))
                queue.append((R1, R2))
            else:
                queue.append((L1, R2))
                queue.append((L2, R1))
        return True
