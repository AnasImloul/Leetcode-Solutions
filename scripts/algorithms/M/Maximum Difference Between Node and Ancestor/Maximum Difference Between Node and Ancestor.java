// Runtime: 1 ms (Top 70.91%) | Memory: 41.7 MB (Top 98.42%)
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
    public int maxAncestorDiff(TreeNode root) {

        if (root == null) return 0;

        return find(root, Integer.MAX_VALUE, Integer.MIN_VALUE);
    }

    public int find(TreeNode root, int min, int max) {
        if (root == null) return Math.abs(max-min);

        min = Math.min(min, root.val);
        max = Math.max(max, root.val);

        return Math.max(find(root.left, min, max), find(root.right, min, max));
    }

}