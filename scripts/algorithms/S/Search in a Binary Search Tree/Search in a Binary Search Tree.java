// Runtime: 0 ms (Top 100.00%) | Memory: 51.2 MB (Top 70.33%)
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null) return root;
        if (root.val == val) {
            return root;
        } else {
            return val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
        }
    }
}