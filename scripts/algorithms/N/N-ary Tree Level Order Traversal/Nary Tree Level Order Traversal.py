class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        
        result = []
        level = [root]
        
        while level:
            current_level = []
            next_level = []
            
            for node in level:
                current_level.append(node.val)
                next_level += node.children
                
            result.append(current_level)
            level = next_level
        
        return result
