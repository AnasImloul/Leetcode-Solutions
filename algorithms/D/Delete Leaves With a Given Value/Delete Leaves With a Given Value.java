class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if(root==null)
            return root;
        root.left = removeLeafNodes(root.left,target);
        root.right = removeLeafNodes(root.right,target);
        if(root.left == null && root.right == null && root.val == target)
            root = null;
        return root;
    }
}