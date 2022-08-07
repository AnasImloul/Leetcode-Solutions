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
    def construct(self, grid: List[List[int]]) -> 'Node': # grid is a square
        end = len(grid)
        gridSum = sum([sum(row) for row in grid])
        
        if gridSum == end**2:
            return Node(1, True)
        
        elif gridSum == 0:
            return Node(0, True)
        
        else:
            node = Node(None, False)
            end //= 2
            node.topLeft = self.construct([row[:end] for row in grid[:end]])
            node.bottomLeft = self.construct([row[:end] for row in grid[end:]])
            node.topRight = self.construct([row[end:] for row in grid[:end]])
            node.bottomRight = self.construct([row[end:] for row in grid[end:]])
            
        return node

