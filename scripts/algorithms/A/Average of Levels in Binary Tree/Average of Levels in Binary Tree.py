# Runtime: 112 ms (Top 18.89%) | Memory: 16.6 MB (Top 49.70%)
# Definition for a binary tree node.
# class TreeNode:
# def __init__(self, val=0, left=None, right=None):
# self.val = val
# self.left = left
# self.right = right
class Solution:
# O(n) || O(h) where h is the height of the tree
# Runtime: 70ms 63.75% || Memory: 16.5mb 87.89%
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:

        queue = deque([root])
        result = []

        while queue:
            runningSum = 0
            newLevelSize = 0
            for i in range(len(queue)):
                currNode = queue.popleft()

                runningSum += currNode.val
                newLevelSize += 1

                if currNode.left:
                    queue.append(currNode.left)
                if currNode.right:
                    queue.append(currNode.right)

            secretFormula = (runningSum/newLevelSize)

            result.append(secretFormula)

        return result