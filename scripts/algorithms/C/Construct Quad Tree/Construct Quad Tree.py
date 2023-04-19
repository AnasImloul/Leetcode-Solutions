"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def is_grid_a_leaf(mylist, n):
            x = mylist[0][0]
            for i in range(n):
                for j in range(n):
                    if mylist[i][j] != x:
                        return (0,0)
            return (1,x)
        
        def tree_builder(currlist) -> 'Node':
            node = Node()
            n = len(currlist)
            node.isLeaf, node.val = is_grid_a_leaf(currlist, n)
            
            if node.isLeaf:
                node.topLeft = node.topRight = node.bottomLeft = node.bottomRight = None
            else:
                top_left = [[row[i] for i in range(n//2)] for row in currlist[0:n//2]]
                top_right= [[row[i] for i in range(n//2,n)] for row in currlist[0:n//2]]
                bot_left = [[row[i] for i in range(n//2)] for row in currlist[n//2:n]]
                bot_right= [[row[i] for i in range(n//2,n)] for row in currlist[n//2:n]]
                node.topLeft = tree_builder(top_left)
                node.topRight = tree_builder(top_right)
                node.bottomLeft = tree_builder(bot_left)
                node.bottomRight = tree_builder(bot_right)
            return node
        
        return tree_builder(grid)