// Runtime: 0 ms (Top 100.00%) | Memory: 41.8 MB (Top 57.76%)
class Solution {
    public int sumOfLeftLeaves(TreeNode root) {

        if(root==null)
            return 0;

        if(root.left!=null && root.left.left==null && root.left.right==null){
            return root.left.val + sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
        }else{
            return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
        }

    }
}