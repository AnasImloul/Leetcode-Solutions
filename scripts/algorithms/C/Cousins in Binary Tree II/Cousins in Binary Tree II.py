# Runtime: 122 ms (Top 76.84%) | Memory: 65.20 MB (Top 70.53%)

from collections import deque
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        pq = deque()
        pq.append((root.val, root))

        while pq:
            n = len(pq)

			# calculate levelSum at each level
            levelSum = 0
            for localSum, node in pq:
                levelSum += node.val

            for i in range(n):
                localSum, node = pq.popleft()

				# calculate childSum
                childSum = 0
                if node.left: childSum += node.left.val
                if node.right: childSum += node.right.val

				# queue children with childSum
                if node.left: pq.append((childSum, node.left))
                if node.right: pq.append((childSum, node.right))

				# new node value is levelSum - localSum
                node.val = levelSum - localSum

        return root
