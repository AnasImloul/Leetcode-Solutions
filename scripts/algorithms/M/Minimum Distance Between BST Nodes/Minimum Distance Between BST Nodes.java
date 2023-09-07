// Runtime: 0 ms (Top 100.0%) | Memory: 40.00 MB (Top 72.0%)

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
    
    int mini=Integer.MAX_VALUE;

    public void find(TreeNode root,ArrayList<Integer>arr){
    
    if(root==null){
        return;
    }
    
    
    arr.add(root.val);
    
    find(root.left,arr);
    
    for(int i=arr.size()-2;i>=0;i--){
    
        mini=Math.min(mini,Math.abs(root.val-arr.get(i)));
    }
    
    find(root.right,arr);
    
    arr.remove(arr.size()-1);
    }

    public int minDiffInBST(TreeNode root) {
    ArrayList<Integer>arr=new ArrayList<>();
    find(root,arr);
    return mini;    
    }
}