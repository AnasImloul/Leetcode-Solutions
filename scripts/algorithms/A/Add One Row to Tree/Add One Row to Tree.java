// Runtime: 0 ms (Top 100.0%) | Memory: 44.40 MB (Top 37.52%)

class Solution {
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (d == 1) return new TreeNode(v, root, null);
        else if (d == 2) {
            root.left = new TreeNode(v, root.left, null);
            root.right = new TreeNode(v, null, root.right);
        } else {
            if (root.left != null) addOneRow(root.left, v, d-1);
            if (root.right != null) addOneRow(root.right, v, d-1);
        }
        return root;
    }
}
