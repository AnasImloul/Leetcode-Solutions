/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int count = 0;
    public int minCameraCover(TreeNode root) {
        if(helper(root) == -1)
            count++;
        return count;
    }
    
    //post order
    //0 - have camera
    //1 - covered
    //-1 - not covered
    public int helper(TreeNode root) {
        if(root == null)
            return 1;
        int left = helper(root.left);
        int right = helper(root.right);
        if(left == -1 || right == -1) {
            count++;
            return 0;
        }
        if(left == 0 || right == 0)
            return 1;
        
        return -1;
    }
}
