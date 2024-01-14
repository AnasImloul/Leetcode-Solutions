// Runtime: 40 ms (Top 94.14%) | Memory: 19.30 MB (Top 21.03%)

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        
        if not root:
            
            # Quick response for empty tree
            return []
        
        traversal_q = [root]
        
        average = []
        
        while traversal_q:
            
            # compute current level average
            cur_avg = sum( (node.val for node in traversal_q if node) ) / len(traversal_q)
            
            # add to result
            average.append( cur_avg )
            
            # update next level queue
            next_level_q = [ child for node in traversal_q for child in (node.left, node.right) if child ]
            
            # update traversal queue as next level's
            traversal_q = next_level_q
            
        return average
