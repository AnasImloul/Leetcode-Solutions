# Runtime: 305 ms (Top 5.46%) | Memory: 15.4 MB (Top 49.03%)
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def findRightMost(self, root, level, requiredLevel):
        if not root:
            return root
        if level == requiredLevel:
            return root
        right = self.findRightMost(root.right, level + 1, requiredLevel)
        if right:
            return right
        return self.findRightMost(root.left, level + 1, requiredLevel)
    def findLeftMost(self, root, level, requiredLevel):
        if not root:
            return root
        if level == requiredLevel:
            return root
        left = self.findLeftMost(root.left, level + 1, requiredLevel)
        if left:
            return left
        return self.findLeftMost(root.right, level + 1, requiredLevel)
    def findRightMostFromRoot(self, rootLevelInfo, requiredLevel, currentRight):
        if currentRight:
            if currentRight.right:
                return currentRight.right
            if currentRight.left:
                return currentRight.left
        root, rootlevel = rootLevelInfo
        rightMost = self.findRightMost(root, rootlevel, requiredLevel)
        while not rightMost and root:
            root = root.right if root.right else root.left
            rootlevel += 1
            rightMost = self.findRightMost(root, rootlevel, requiredLevel)
            if rightMost:
                rootLevelInfo[-1] = rootlevel
                rootLevelInfo[0] = root
        return rightMost
    def findLeftMostFromRoot(self, rootLevelInfo, requiredLevel, currentLeft):
        if currentLeft:
            if currentLeft.left:
                return currentLeft.left
            if currentLeft.right:
                return currentLeft.right
        root, rootlevel = rootLevelInfo
        leftMost = self.findLeftMost(root, rootlevel, requiredLevel)
        while not leftMost and root:
            root = root.left if root.left else root.right
            rootlevel += 1
            leftMost = self.findLeftMost(root, rootlevel, requiredLevel)
            if leftMost:
                rootLevelInfo[-1] = rootlevel
                rootLevelInfo[0] = root

        return leftMost
    def stitch(self, root):
        if not root:
            return
        leftRootStart = [root.left, 1]
        rightRootStart = [root.right, 1]
        connectLevel = 1
        currentLeft = self.findLeftMostFromRoot(rightRootStart, 1, None)
        currentRight = self.findRightMostFromRoot(leftRootStart, 1, None)
        while currentLeft and currentRight:
            currentRight.next = currentLeft
            connectLevel += 1
            currentLeft = self.findLeftMostFromRoot(rightRootStart, connectLevel, currentLeft)
            currentRight = self.findRightMostFromRoot(leftRootStart, connectLevel, currentRight)

        self.stitch(root.left)
        self.stitch(root.right)
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return root
        self.stitch(root)
        return root