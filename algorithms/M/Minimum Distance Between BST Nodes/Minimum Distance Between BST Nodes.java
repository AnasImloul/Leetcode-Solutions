/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public int minDiffInBST(TreeNode root) {
        
        int prev = -1;
        int diff = Integer.MAX_VALUE;
        TreeNode temp = root;
        while(temp!=null){
            if(temp.left==null){
                if(prev!=-1) diff = Math.min(temp.val-prev,diff);
                prev = temp.val;
                temp = temp.right;
            }else{
                TreeNode left = temp.left;
                while(left.right!=null&&left.right!=temp){
                    left = left.right;
                }
                if(left.right==null){
                    left.right = temp;
                    temp = temp.left;
                }else{
                    left.right = null;
                    if(prev!=-1) diff = Math.min(temp.val-prev,diff);
                    prev = temp.val;
                    temp = temp.right;
                }
            }
        }
        return diff;
    }
}
