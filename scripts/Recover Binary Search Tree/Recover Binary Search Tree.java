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
    PriorityQueue<Integer> li = new PriorityQueue<Integer>();
    public void recoverTree(TreeNode root) {
      liele(li,root); //adding elements to PriorityQueue
      arrange(li,root); //checking and arranging elements
    }
    public void liele(PriorityQueue<Integer> li,TreeNode root){
        if(root==null) return;
        
        liele(li,root.left);
        li.offer(root.val);
        liele(li,root.right);
    }
    public void arrange(PriorityQueue<Integer> li,TreeNode root){
        if(root==null) return;
        
        arrange(li,root.left);
        int s=li.poll();
        if(root.val!=s){
            root.val=s;
        }
        arrange(li,root.right);
    }
}
