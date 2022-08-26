// Runtime: 0 ms (Top 100.00%) | Memory: 41.5 MB (Top 73.31%)
class Solution {
    TreeNode inRoot = new TreeNode();
    TreeNode temp = inRoot;
    public TreeNode increasingBST(TreeNode root) {
        inorder(root);
        return inRoot.right;
    }
    public void inorder(TreeNode root) {
        if(root==null)
            return;
        inorder(root.left);
        temp.right = new TreeNode(root.val);
        temp = temp.right;
        inorder(root.right);
    }
}