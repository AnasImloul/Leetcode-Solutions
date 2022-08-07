class Solution {
    public boolean isValidBST(TreeNode root) {
        return dfs(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    public boolean dfs(TreeNode root, int min, int max) {
        if (root.val < min || root.val > max || (root.val == Integer.MIN_VALUE && root.left != null) ||                    (root.val == Integer.MAX_VALUE && root.right != null)) return false;
        boolean leftRight = true;
        if (root.left == null && root.right == null) return true;
        if (root.left != null) {
            leftRight = dfs(root.left, min, root.val - 1);
        }
        if (root.right != null) {
            leftRight = dfs(root.right, root.val + 1, max) && leftRight;
        }
        return leftRight;
    }
}
