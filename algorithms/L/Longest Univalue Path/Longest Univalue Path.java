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
    int maxLen = 0;
    public int longestUnivaluePath(TreeNode root) {
        lup(root);
        return maxLen;
    }
    public int lup(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = lup(root.left);
        int right = lup(root.right);
        int leftMax = 0;
        int rightMax = 0;
        if (root.left != null && root.val == root.left.val) {
            leftMax = left + 1;
        }
        if (root.right != null && root.val == root.right.val) {
            rightMax = right + 1;
        }
        maxLen = Math.max(maxLen, leftMax + rightMax);
        return Math.max(leftMax, rightMax);
    }
}
