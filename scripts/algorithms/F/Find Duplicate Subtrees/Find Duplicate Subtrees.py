class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        ans = []
        path_map = {}
        
        def dfs(node):
            if not node:
                return "#"
            
            path = ",".join([str(node.val), dfs(node.left), dfs(node.right)])
            
            if path in path_map:
                path_map[path] += 1
                if  path_map[path] == 2:
                    ans.append(node)
            else:
                path_map[path] = 1
                
            return path
        
        
        dfs(root)
        return ans
