class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        
        # DFS solution
        output = []
        stack = [(root, '')]
        
        while stack:
            node, path = stack.pop()
            path += str(node.val)
            
            if not node.left and not node.right:
                output.append(path)
                
            path += '->'
            if node.left:
                stack.append((node.left, path))
            if node.right:
                stack.append((node.right, path))
                
        return output
