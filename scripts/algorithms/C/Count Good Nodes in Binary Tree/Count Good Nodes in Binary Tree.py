// Runtime: 132 ms (Top 87.49%) | Memory: 31.70 MB (Top 89.21%)

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        # Our counter for the good nodes.
        count = 0
        
        def helper(node, m):
            nonlocal count
			# If we run out of nodes return.
            if not node:
                return
			# If the current node val is >= the largest observed in the path thus far.
            if node.val >= m:
			    # Add 1 to the count and update the max observed value.
                count += 1
                m = max(m, node.val)
			# Traverse l and r subtrees.
            helper(node.left, m)
            helper(node.right, m)
                
        helper(root, root.val)
        return count
