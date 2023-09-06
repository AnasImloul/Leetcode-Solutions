// Runtime: 0 ms (Top 100.0%) | Memory: 44.92 MB (Top 83.3%)

class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root==null) return null;
        
        if(key<root.val){                            
            root.left = deleteNode(root.left,key);
            return root;
        }
        
        else if(key>root.val){
            root.right = deleteNode(root.right,key);
            return root;
        }
        
        else{
            if(root.left==null){
                return root.right;
            }
            else if(root.right==null){
                return root.left;
            }
            else{
                TreeNode min = root.right;
                while(min.left!=null){
                    min = min.left;
                }
                
                root.val = min.val;
                root.right = deleteNode(root.right,min.val);
                return root;
            }
        }
    }
}