class Solution {
    boolean ans=true;
    int firstVal=0;
    public boolean isUnivalTree(TreeNode root) {
        if(root==null)
          return ans; 
        firstVal=root.val;
        traversal(root);
      return ans;
    }
  private void traversal(TreeNode root)
  {
    if(root==null)
      return;
    if(root.val!=firstVal)
        ans=false;
    traversal(root.left);
    traversal(root.right);
  }
  
}
