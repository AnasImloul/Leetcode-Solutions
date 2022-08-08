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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        findAndAdd(root, val, depth, 1);
        return root; 
    }

    public void findAndAdd(TreeNode root, int val, int depth, int currDepth){
        if(depth == 1 && currDepth == 1){
            root.left = new TreeNode(root.val, root.left, root.right);
            root.right = null;
            root.val = val;
            return;
        }
        if(root == null)
            return;
        if(currDepth == depth - 1){
            root.left = new TreeNode(val, root.left, null);
            root.right = new TreeNode(val, null, root.right);
        }else{
            findAndAdd(root.left, val, depth, currDepth + 1);
            findAndAdd(root.right, val, depth, currDepth + 1);
        }
        return;
    }
}
