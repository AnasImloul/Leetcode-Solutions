// Runtime: 0 ms (Top 100.0%) | Memory: 45.20 MB (Top 7.32%)

class Solution {   
   public TreeNode helper(TreeNode root,int limit, int sumTillNow)
    {
        if(root == null)  return null;
        
        if(root.left == null && root.right == null)
             return root.val + sumTillNow < limit ? null : root;
        
        root.left = helper(root.left,limit,sumTillNow + root.val);
        root.right = helper(root.right,limit,sumTillNow + root.val);
        
        return root.left == null && root.right == null ? null : root;
    }
    
    
    public TreeNode sufficientSubset(TreeNode root, int limit){
        return helper(root,limit,0);
    }
}
