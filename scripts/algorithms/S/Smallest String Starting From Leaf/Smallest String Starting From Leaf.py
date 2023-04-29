class Solution:
    res = 'z' * 13           # init max result, tree depth,  12< log2(8000) < 13
    
    def smallestFromLeaf(self, root: TreeNode) -> str:
        
        def helper(node: TreeNode, prev):
            prev = chr(97 + node.val) + prev
            
            if not node.left and not node.right:
                self.res = min(self.res, prev)
                return
            
            if node.left:
                helper(node.left, prev)
            if node.right:
                helper(node.right, prev)
        
        helper(root, "")
        return self.res