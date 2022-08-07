/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> path_to_p= new ArrayList<>();
        List<TreeNode> path_to_q= new ArrayList<>();
        getPath(root,p,path_to_p);
        getPath(root,q,path_to_q);
        int n=path_to_q.size()>path_to_p.size()?path_to_p.size():path_to_q.size();
        TreeNode anscesstor=root;
        for(int i=0;i<n;i++){
            if(path_to_q.get(i)==path_to_p.get(i)) anscesstor=path_to_p.get(i);
        }
        return anscesstor;
        
        
    }
    
    boolean getPath(TreeNode root, TreeNode target,List<TreeNode> list){
        if(root==null) return false;
        list.add(root);
        if(root==target) return true;
        if(getPath(root.left,target,list) || getPath(root.right,target,list)){
            return true;
        }
        list.remove(list.size()-1);
        return false;
    }
}
