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
    int element,count;
    
    public int kthSmallest(TreeNode root, int k) {
        inorderTraversal(root,k);
        return element;
    }
    
    
    public void inorderTraversal(TreeNode root,int k){
        if(root.left != null){
            inorderTraversal(root.left,k);
        }
        count++;
        if(count==k){
            element = root.val;
        }
        
        if(root.right != null){
            inorderTraversal(root.right,k);
        }
    }
}
