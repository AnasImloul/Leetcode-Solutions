class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
                                # dfs traverses  the node's subtree and returns the max
                                # level in the subtree if dfs(node.left) == dfs(node.right) 
                                # then node is a candidate for the answer. The dict d 
                                # stores the the most recent candidate node by key = maxLevel
                                # for the subtree. The root returns the actual max level,
                                # so the answer is d[dfs(root)]
        
        def dfs(node = root, level = 0):
            if not node:
                return level-1
            
            l, r = dfs(node.left, level+1), dfs(node.right, level+1)
            
            if l == r:
                d[l] = node
                
            return max(l,r)
        
        d = {}
        return d[dfs()]