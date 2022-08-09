"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

#DFS
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0
        def dfs(r):
            
            if not r.children:
                return 1
            depth = 0
            for child in r.children:
                depth = max(depth, dfs(child) + 1)
            
            return depth

        return dfs(root)
		
		
#BFS 
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0
        def bfs(r):
            
            q = []
            q.append(root)
            level = 0
            while q != []:
                    num_nodes = len(q)
                    level += 1
                    for _ in  range(num_nodes):
                        node = q.pop(0)

                        for child in node.children:
                            q.append(child)
            return level

        return bfs(root)

