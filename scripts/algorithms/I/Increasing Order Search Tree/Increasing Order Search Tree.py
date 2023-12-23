// Runtime: 44 ms (Top 21.66%) | Memory: 17.30 MB (Top 23.65%)

class Solution:
    def increasingBST(self, node: TreeNode) -> TreeNode:
        dummy = tail = TreeNode()
        while node is not None:
            if node.left is not None:
                predecessor = node.left
                while predecessor.right is not None:
                    predecessor = predecessor.right
                
                predecessor.right = node
                left, node.left = node.left, None
                node = left
            else:
                tail.right = tail = node
                node = node.right
        
        return dummy.right
