class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root: return []
        
        ans = []
        
        node = root 
        
        q = collections.deque([node])
        
        order = -1 
        
        while q:
            order = -order
            level = []
            for _ in range(len(q)):
                node = q.popleft()
                
                level.append(node.val)
                
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                    
            ans.append(level[::order])
                
        return ans
