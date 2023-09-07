// Runtime: 0 ms (Top 100.0%) | Memory: 39.81 MB (Top 82.6%)

class Solution {
    public TreeNode pruneTree(TreeNode root) {
        
        if(root == null) return root;
        
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);
    
        if(root.left == null && root.right == null && root.val == 0) return null;
        else return root;
    }
}