class Solution {
    public TreeNode invertTree(TreeNode root) {
        
        swap(root);
        return root;
    }
	
    private static void swap(TreeNode current) {
        if (current == null) {
            return;
        }
        
        swap(current.left);
        swap(current.right);
        
        TreeNode temp = current.left;
        current.left = current.right;
        current.right = temp;
    }
}
