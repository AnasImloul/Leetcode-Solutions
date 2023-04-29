# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:

        # find a set of deepest nodes first
        deepest_nodes = [0]
        self.find_deepest(root, 0, deepest_nodes)
        
        # extract the depth and also make a set out of the values
        targets = set(deepest_nodes[1:])

        # get the subtree
        return self.find_merge(root, targets)[0]

    def find_deepest(self, node, current_depth, deepest_nodes):

        # make a check
        if not node:
            return
        
        # make a check if we are a deep node
        if current_depth > deepest_nodes[0]:
            deepest_nodes.clear()
            deepest_nodes.append(current_depth)
            deepest_nodes.append(node.val)
        elif current_depth == deepest_nodes[0]:
            deepest_nodes.append(node.val)
        
        # go deeper
        self.find_deepest(node.left, current_depth+1, deepest_nodes)
        self.find_deepest(node.right, current_depth+1, deepest_nodes)
    
    def find_merge(self, node, targets):

        # make a check
        if not node:
            return None, set()

        # check whether we are a target
        found = set()
        if node.val in targets:
            found.add(node.val)

        # go deeper and get result nodes
        nleft, left = self.find_merge(node.left, targets)
        if nleft is not None:
            return nleft, set()
        nright, right = self.find_merge(node.right, targets)
        if nright is not None:
            return nright, set()

        # merge the found set
        found = found | left | right

        # check whether we found all
        if not (targets - found):
            return node, set()
        else:
            return None, found