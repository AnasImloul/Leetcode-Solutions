
import itertools
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraHelper(self, root: Optional[TreeNode]) -> (int, int):
        # Return 3 things:
        # cam, uncam, uncov
        # cam(era) is best score for valid tree with camera at root
        # uncam(era) is best score for valid tree without camera at root
        # uncov(ered) is best score for invalid tree, where the only invalidity (i.e. the only uncovered node) is the root node
        
        # Note: maxint (float("inf")) is used to signify situations that don't make sense or can't happen.
        # Anywhere there is a float("inf"), you can safely replace that with a 1 as 1 is as bad or worse than worst practical,
        # but I stick with maxint to highlight the nonsensical cases for the reader!
        
        if not root.left and not root.right:
            # base case: leaf
            # Note: "Uncam" setting doesn't make much sense (a leaf with no parents can either have a camera or be uncovered,
            #       but not covered with no camera)
            return 1, float("inf"), 0
        
        if root.left:
            left_cam, left_uncam, left_uncov = self.minCameraHelper(root.left)
        else:
            # base case: empty child
            # Need to prevent null nodes from providing coverage to parent, so set that cost to inf
            left_cam, left_uncam, left_uncov = float("inf"), 0, 0
            
        if root.right:
            right_cam, right_uncam, right_uncov = self.minCameraHelper(root.right)
        else:
            # base case: empty child
            # Need to prevent null nodes from providing coverage to parent, so set that cost to inf
            right_cam, right_uncam, right_uncov = float("inf"), 0, 0
            
        # Get the possible combinations for each setting    
        cam_poss = itertools.product([left_cam, left_uncam, left_uncov], [right_cam, right_uncam, right_uncov])
        uncam_poss = [(left_cam, right_cam), (left_uncam, right_cam), (left_cam, right_uncam)]
        uncov_poss = [(left_uncam, right_uncam)]
        
        # Compute costs for each setting
        cam = min([x + y for x, y in cam_poss]) + 1
        uncam = min([x + y for x, y in uncam_poss])
        uncov = min([x + y for x, y in uncov_poss])
        
        return cam, uncam, uncov
                    
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        cam, uncam, _ = self.minCameraHelper(root)
        return min(cam, uncam)

