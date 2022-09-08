// Runtime: 1 ms (Top 64.02%) | Memory: 42.7 MB (Top 25.40%)
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isSymmetric(root.left,root.right);
    }

    public boolean isSymmetric(TreeNode rootLeft, TreeNode rootRight) {
        if(rootLeft == null && rootRight == null) {return true;}
        if(rootLeft == null || rootRight == null) {return false;}
        if (rootLeft.val != rootRight.val) {return false;}
        else
            return isSymmetric(rootLeft.right, rootRight.left) && isSymmetric(rootLeft.left, rootRight.right);
    }
}