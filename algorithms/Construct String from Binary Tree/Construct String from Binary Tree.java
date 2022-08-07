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
    public String tree2str(TreeNode root) {
        
        if(root==null) return "";
        if(root.left==null&&root.right==null) return Integer.toString(root.val);
        String left = tree2str(root.left);
        String right = tree2str(root.right);
        StringBuilder sb = new StringBuilder();
        sb.append(root.val);
        sb.append("(").append(left).append(")");
        if(root.right!=null) sb.append("(").append(right).append(")");
        return sb.toString();
    }
}
