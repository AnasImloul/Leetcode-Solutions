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
    static class Pair{
        int withRob=0;
        int withoutRob=0;
    } 
    public int rob(TreeNode root) {
        Pair nodeRob=rob_(root);
        
        return Math.max(nodeRob.withRob,nodeRob.withoutRob);
    }
    
    public Pair rob_(TreeNode root){
        if(root==null){
            return new Pair();
        }
        
        Pair l=rob_(root.left);
        Pair r=rob_(root.right);
        
        Pair nodeRob=new Pair();
        nodeRob.withRob=root.val+l.withoutRob+r.withoutRob;
                nodeRob.withoutRob=Math.max(l.withRob,l.withoutRob)+Math.max(r.withRob,r.withoutRob);
        return nodeRob;
    }
}
