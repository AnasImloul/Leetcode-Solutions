// Runtime: 8 ms (Top 84.82%) | Memory: 54.1 MB (Top 87.52%)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
   static class Pair{
       int left=-1;
       int right=-1;
       int maxLen=0;
   }
    public int longestZigZag(TreeNode root) {
        Pair ans=longestZigZag_(root);
        return ans.maxLen;
    }

    public Pair longestZigZag_(TreeNode root) {
        if(root==null)
            return new Pair();
        Pair l=longestZigZag_(root.left);
        Pair r=longestZigZag_(root.right);

        Pair myAns=new Pair();
        myAns.left=l.right+1;
        myAns.right=r.left+1;
        int max=Math.max(myAns.left,myAns.right);
        myAns.maxLen=Math.max(max,Math.max(l.maxLen,r.maxLen));
        return myAns;

    }

}