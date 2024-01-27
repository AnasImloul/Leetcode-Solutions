// Runtime: 1 ms (Top 73.06%) | Memory: 47.50 MB (Top 96.63%)

class Solution {
    
    public void swapOddLevel(TreeNode right, TreeNode left, boolean reverse) {
        if (right == null || left == null) return;
        if (reverse) {
            int temp = left.val;
            left.val = right.val;
            right.val = temp;
        } 
        reverse = !reverse;
        swapOddLevel(right.right, left.left, reverse);
        swapOddLevel(right.left, left.right, reverse);
    }
    
    public TreeNode reverseOddLevels(TreeNode root) {
        if (root.left == null) return root;
        swapOddLevel(root.right, root.left, true);
        return root;
    }
}
