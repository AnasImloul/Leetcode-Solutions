// Runtime: 0 ms (Top 100.0%) | Memory: 40.83 MB (Top 42.1%)

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
    List<Integer> li = new LinkedList<Integer>();
    public List<Integer> inorderTraversal(TreeNode root) {
     if(root == null){
         List<Integer> li = new LinkedList<Integer>();
         return li ;
     }
     inorderTraversal(root.left);     
     li.add(root.val);     
     inorderTraversal(root.right);
     return li;

    }
    
}