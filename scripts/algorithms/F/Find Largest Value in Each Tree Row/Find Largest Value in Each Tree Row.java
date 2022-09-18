// Runtime: 6 ms (Top 12.42%) | Memory: 45.3 MB (Top 32.64%)
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
    private List<Integer> li=new ArrayList<>();

    public List<Integer> largestValues(TreeNode root) {

        if(root==null) return li; //if root is NULL

        //using bfs(level-order)
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size=q.size();
            int res=Integer.MIN_VALUE;
            while(size-->0){
                TreeNode temp=q.poll();
                if(temp.left!=null) q.add(temp.left);
                if(temp.right!=null) q.add(temp.right);
                res =Math.max(res,temp.val); //comparing every node in each level to get max
            }
            li.add(res); //adding each level Max value to the list
        }
        return li;
    }
}