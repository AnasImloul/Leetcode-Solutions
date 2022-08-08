# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        # declaire a variable maxSum to hold the max path sum
        self.maxSum=0
        def getMax(root):
            # return max,min,val - if root is null, valid BST
            if not root : return (float("-inf"),float("inf"),0)
            # traverse left and right part
            leftMax,leftMin,leftMaxSum=getMax(root.left)
            rightMax,rightMin,rightMaxSum=getMax(root.right)
            # if a valid BST
            if root.val>leftMax and root.val<rightMin:
                # update maxSum
                self.maxSum=max(self.maxSum,root.val+leftMaxSum+rightMaxSum)
                # return maximum and minimum node values starting from that node and pathSum
                return max(root.val,rightMax),min(root.val,leftMin),root.val+leftMaxSum+rightMaxSum
            # if not a BST - set an impossible condition such than the root is also returned as non-BST
            return  (float("inf"),float("-inf"),0)
        getMax(root)    
        return self.maxSum
        
            
