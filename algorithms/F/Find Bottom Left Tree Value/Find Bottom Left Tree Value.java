
class Solution {
    int max = Integer.MIN_VALUE;
    int res = -1;
    public int findBottomLeftValue(TreeNode root) {
        check(root,0);
        return res;
    }
    void check(TreeNode root, int h){
        if(root==null)
            return;
        if(h>max){
            max=h;
            res = root.val;
        }
        check(root.left,h+1);
        check(root.right,h+1);
    }
}