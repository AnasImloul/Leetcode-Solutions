// Runtime: 0 ms (Top 100.00%) | Memory: 41.8 MB (Top 20.63%)
class Solution {
    int ans = Integer.MAX_VALUE;
    boolean x = true;

    public int findSecondMinimumValue(TreeNode root) {
        go(root);
        return x ? -1 : ans;
    }

    private void go(TreeNode root) {
        if (root == null) return;
        if (root.left != null) {
            if (root.left.val == root.val) go(root.left);
            else {
                x = false;
                ans = Math.min(ans, root.left.val);
            }
        }
        if (root.right != null) {
            if (root.right.val == root.val) go(root.right);
            else {
                x = false;
                ans = Math.min(ans, root.right.val);
            }
        }
    }
}