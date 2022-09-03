// Runtime: 0 ms (Top 100.00%) | Memory: 42.3 MB (Top 40.74%)
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
    List<Integer> res = new ArrayList<>();
    public List<Integer> postorderTraversal(TreeNode root) {
        traversal(root);
        return res;
    }

    public void traversal(TreeNode root){
        if(root == null)
            return;
        traversal(root.left);
        traversal(root.right);
        res.add(root.val);
    }
}