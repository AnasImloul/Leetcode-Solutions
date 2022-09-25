// Runtime: 86 ms (Top 5.00%) | Memory: 44 MB (Top 76.22%)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {

    public int treeHeight(TreeNode root){
        if (root == null)
            return 0;

        int left = treeHeight(root.left);
        int right = treeHeight(root.right);

        return ( Math.max(left,right) + 1);

    }

    public boolean isBalanced(TreeNode root) {

        if (root == null)
            return true;

        boolean leftBalanced = isBalanced( root.left);
        boolean rightBalanced = isBalanced( root.right);
        int leftHeight = treeHeight(root.left);
        int rightHeight = treeHeight(root.right);

        //Return true only when all conditions are true
        return (leftBalanced && rightBalanced && Math.abs(leftHeight - rightHeight) <= 1);

    }
}