// Runtime: 0 ms (Top 100.0%) | Memory: 44.10 MB (Top 76.35%)

class Solution {
    private int count = 0;
    private int result = 0;

    public int kthSmallest(TreeNode root, int k) {
        inorderTraversal(root, k);
        return result;
    }

    private void inorderTraversal(TreeNode node, int k) {
        if (node == null || count >= k) {
            return;
        }

        inorderTraversal(node.left, k);

        count++;
        if (count == k) {
            result = node.val;
            return;
        }

        inorderTraversal(node.right, k);
    }
}
