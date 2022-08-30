// Runtime: 7 ms (Top 58.14%) | Memory: 45.5 MB (Top 29.64%)
class Solution {
    String result = null;
    public String smallestFromLeaf(TreeNode root) {
        build(root, new StringBuilder());
        return result;
    }

    public void build(TreeNode root, StringBuilder str) {
        if (root == null) return;

        StringBuilder sb = new StringBuilder(str).insert(0, String.valueOf(intToChar(root.val)));

        if (root.left == null && root.right == null) { // we are on a leaf node
            result = result == null || sb.toString().compareTo(result) < 0 ? sb.toString() : result;
            return;
        }
        build(root.left, sb); // build left child
        build(root.right, sb); // build right child
    }

    // turns an int (0-25) into a Character ex: 0 -> a, 1 -> b, 2 -> c
    public Character intToChar(int i) {
        return (char) (i + 'a');
    }
}