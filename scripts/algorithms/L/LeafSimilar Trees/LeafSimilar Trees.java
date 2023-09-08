// Runtime: 0 ms (Top 100.0%) | Memory: 40.21 MB (Top 60.0%)

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
  
    List<Integer> set1,set2;
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        set1=new ArrayList<>();
        set2=new ArrayList<>();
        
        getLeafNodes(root1,set1);
        getLeafNodes(root2,set2);
                
        return set1.equals(set2); //At last we compare the two list formed and check the sequence
    }
    
	//The function below is to extract all the leaf nodes in the sequence mentioned in the examples
    public void getLeafNodes(TreeNode root,List<Integer> set)
    {
	// This code represents inorder traversal
        if(root==null)
            return;
        
        getLeafNodes(root.left,set);
        
        if(root.left==null && root.right==null)
        {
            if(set==null)
            {
                set=new ArrayList<Integer>();
            }
            set.add(root.val);return;
        }
        
        getLeafNodes(root.right,set);
    }
}