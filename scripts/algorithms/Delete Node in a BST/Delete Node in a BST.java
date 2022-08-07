class Solution {
    
	//This function returns us the ceiling node for the given node 
    public TreeNode getSucc(TreeNode root) {
        root = root.right;
        while(root.left!=null)
            root=root.left;
        return root;
    }
    
    public TreeNode deleteNode(TreeNode root, int key) {
        
		//If node is null return null
        if(root==null)
            return null;
        
		//If node value is less than key we point towards the right sub tree
        if(root.val < key) {
            root.right = deleteNode(root.right,key);
        }
		//If node value is greater than key we point towards left sub tree
        else if(root.val > key) {
            root.left = deleteNode(root.left,key);
        }
		//We enter this condition when we reach at that node that is equal to key value 
        else {
		//we return right node if its left node is null
            if(root.left==null)
                return root.right;
		//we return left node if the right node is null
            else if(root.right==null)
                return root.left;
		//we enter this condition when both left and right nodes are present
            else {
			//We find the ceiling node for the current node
                TreeNode succ = getSucc(root);
			//We replace the value of the succ node and root node
                root.val = succ.val;
			//Now we delete the duplicate entry of the succ node from right sub tree
                root.right = deleteNode(root.right,succ.val);
            }
        }
        
        return root;
    }
}
