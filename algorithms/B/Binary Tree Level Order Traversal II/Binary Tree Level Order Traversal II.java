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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode> al=new LinkedList<>();
        List<List<Integer>> fal=new LinkedList<>();
        if(root==null) return fal;
        al.offer(root);
        while(!al.isEmpty()){
            List<Integer> aal=new LinkedList<>();
            int num=al.size();
            for(int i=0;i<num;i++){
                if(al.peek().left != null){
                    al.offer(al.peek().left);
                }
                if( al.peek().right != null){
                    al.offer(al.peek().right);
                }
                aal.add(al.poll().val);
            }
            fal.add(0,aal);
        }
        return fal;
    }
}
