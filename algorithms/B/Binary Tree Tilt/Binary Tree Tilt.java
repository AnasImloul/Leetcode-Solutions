class Solution {
    int max = 0;
    public int findTilt(TreeNode root) {
        loop(root);
        return max;
    }
    public int loop(TreeNode root){
        if(root==null) return 0;
        int left = loop(root.left);
        int right = loop(root.right);
        max+= Math.abs(left-right);
        return root.val+left+right;
    }
}