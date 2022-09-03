// Runtime: 1 ms (Top 99.74%) | Memory: 48.6 MB (Top 11.74%)
class Solution {

    int[] ans = new int[1];
    public int maxPathSum(TreeNode root) {
        ans[0]=root.val; //Handle edge case
        dfs(root);
        return ans[0];
    }

    public int dfs(TreeNode root){

        if(root==null)
            return 0;

        int left=Math.max(0,dfs(root.left)); //Check on the left subtree and if returned negative take 0
        int right=Math.max(0,dfs(root.right)); //Check on the right subtree and if returned negative take 0

        int maxInTheNode=root.val+left+right; //Calculating the max while including the root its left and right child.
        ans[0]=Math.max(ans[0],maxInTheNode); //Keeping max globally

        return root.val+Math.max(left,right); //Since only one split is allowed returning the one split that returns max value
    }
}