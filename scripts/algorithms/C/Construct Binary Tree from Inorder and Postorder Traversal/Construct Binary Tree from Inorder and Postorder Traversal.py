import bisect
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def buildTree(self, inorder, postorder):
        """
        7
         2
       -8 
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        ([-4,-10,3,-1], [7]) ((11,-8,2), [7])
        """
        currentSplits = [(inorder, [], [])]
        nodeDirectory = {}
        finalSplits = []
        for nodeVal in reversed(postorder):
            nodeDirectory[nodeVal] = TreeNode(nodeVal)
            for splits, nodes, directions in reversed(currentSplits):
                removing = None
                if nodeVal in splits:
                    removing = (splits, nodes, directions)
                    left = splits[:splits.index(nodeVal)]
                    right = splits[splits.index(nodeVal)+1:]
                    currentSplits.append((left, nodes+[nodeVal], directions + ['left']))
                    if len(left) <= 1:
                        finalSplits.append((left, nodes+[nodeVal], directions + ['left']))
                    currentSplits.append((right, nodes+[nodeVal], directions + ['right']))
                    if len(right) <= 1:
                        finalSplits.append((right, nodes+[nodeVal], directions + ['right']))
                    break
                if removing:
                    currentSplits.remove(removing)
        finalSplits = [splits for splits in finalSplits if splits[0]]

        while finalSplits:
            nodeVal, nodes, directions = finalSplits.pop()
            bottomNode = nodeDirectory[nodeVal[0]] if nodeVal else None
            while nodes:
                attachingNode = nodeDirectory[nodes.pop()]
                attachingDir = directions.pop()
                if attachingDir == 'left':
                    attachingNode.left = bottomNode
                else:
                    attachingNode.right = bottomNode
                bottomNode = attachingNode
        return nodeDirectory[postorder[-1]]
