class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
       if(root == null) return false;
      
      if(root.left == null && root.right == null) return root.val == targetSum;
      
      return hasPathSum(root.right, targetSum - root.val) || hasPathSum(root.left, targetSum - root.val);
    }
}
