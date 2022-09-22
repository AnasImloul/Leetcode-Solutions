// Runtime: 13 ms (Top 90.30%) | Memory: 108.9 MB (Top 39.07%)
class Solution {
    public int pseudoPalindromicPaths (TreeNode root) {
        return helper(root, 0);
    }

    public int helper(TreeNode node, int freq) {
        if (node == null) return 0;

        freq = freq ^ (1 << node.val);
        if (node.left == null && node.right == null) {
            return (freq & (freq - 1)) == 0 ? 1 : 0;
            // return Integer.bitCount(freq) <= 1 ? 1 : 0;
        }
        return helper(node.left, freq) + helper(node.right, freq);
    }
}