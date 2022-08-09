class Solution {
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root==null) return new TreeNode(val);
        if (val > root.val) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        root.right = insertIntoMaxTree(root.right, val);
        return root;
    }
}
