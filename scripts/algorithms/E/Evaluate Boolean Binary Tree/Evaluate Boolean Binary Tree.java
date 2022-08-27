// Runtime: 0 ms (Top 100.00%) | Memory: 42.4 MB (Top 93.53%)
class Solution {
    public boolean evaluateTree(TreeNode root) {
        if(root.val == 1)
            return true;
        if(root.val == 0)
            return false;
        if(root.val == 2)
            return evaluateTree(root.left) || evaluateTree(root.right);
        return evaluateTree(root.left) && evaluateTree(root.right);
    }
}