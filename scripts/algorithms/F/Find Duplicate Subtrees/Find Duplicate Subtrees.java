// Runtime: 1783 ms (Top 5.02%) | Memory: 64.5 MB (Top 11.80%)
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
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> list = new ArrayList<TreeNode>();
        HashSet<String> hashes = new HashSet<String>();
        HashSet<String> added = new HashSet<String>();

        // for each node, perform a dfs traversal and generate a hash
        // check if the hash already exists in a set,
        // if it does, get the treenode and add it to the list
        Stack<TreeNode> s = new Stack<TreeNode>();

        s.add(root);
        while(!s.isEmpty()){
            TreeNode tmp = s.pop();
            dfs(tmp, "", tmp, list, hashes, added);

            if(tmp.left != null){
                s.add(tmp.left);
            }
            if(tmp.right != null){
                s.add(tmp.right);
            }
        }

        return list;

    }

    public void dfs(TreeNode parent, String hash, TreeNode root, List<TreeNode> list, HashSet<String> set, HashSet<String> added){

        Stack<TreeNode> stack = new Stack<TreeNode>();

        stack.add(root);
        //String hash = "";
        hash += root.val + "ROOT,";
        while(!stack.isEmpty()){
            TreeNode tmp = stack.pop();
            //hash += tmp.val + ",";

            if(tmp.left != null){
                hash += tmp.left.val + "L,";
                stack.add(tmp.left);
            }
            else{
                hash+= "NULLL,";
            }
            if(tmp.right != null){
                hash += tmp.right.val + "R,";
                stack.add(tmp.right);
            }
            else{
                hash+="NULLR,";
            }
            if(tmp.left == null && tmp.right == null && stack.isEmpty()){
                if(set.contains(hash)){
                    if(!added.contains(hash)){
                        list.add(parent);
                        added.add(hash);
                    }
                }
                else{
                    set.add(hash);
                }
                return;
            }

        }
    }
}