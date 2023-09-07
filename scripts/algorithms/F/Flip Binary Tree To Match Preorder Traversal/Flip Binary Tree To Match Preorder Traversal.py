# Runtime: 50 ms (Top 21.2%) | Memory: 16.23 MB (Top 89.3%)

class Solution:
    def flipMatchVoyage(self, root, voyage):
        
        # ------------------------------
        
        def dfs(root):
            
            if not root:
                # base case aka stop condition
				# empty node or empty tree
                return True
            
            
            ## general cases
            if root.val != voyage[dfs.idx]:
                
                # current node mismatch, no chance to make correction by flip
                return False
            
            # voyage index moves forward
            dfs.idx += 1
            
            if root.left and (root.left.val != voyage[dfs.idx]):
                
                # left child mismatch, flip with right child if right child exists
                root.right and result.append( root.val )
                
                # check subtree in preorder DFS with child node flip
                return dfs(root.right) and dfs(root.left)
                
            else:
                
                # left child match, check subtree in preorder DFS
                return dfs(root.left) and dfs(root.right)
                
      
        # --------------------------
        
        # flip sequence
        result = []
        
        # voyage index during dfs
        dfs.idx = 0
        
        # start checking from root node
        good = dfs(root)
        
        return result if good else [-1]