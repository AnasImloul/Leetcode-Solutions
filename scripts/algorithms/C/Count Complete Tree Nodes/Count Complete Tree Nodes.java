// Runtime: 0 ms (Top 100.00%) | Memory: 50.7 MB (Top 10.84%)
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

    static int count = 0;

    static void Postorder(TreeNode root){
        if(root == null){
            return;
        }
        Postorder(root.left);
        Postorder(root.right);
        count++;
    }

    public int countNodes(TreeNode root) {
        count = 0;
        Postorder(root);
        return count;
    }
}