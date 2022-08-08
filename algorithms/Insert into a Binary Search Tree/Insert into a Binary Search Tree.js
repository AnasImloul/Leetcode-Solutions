var insertIntoBST = function(root, val) {
    
    if (root == null) {
        return new TreeNode(val);
    }
    
    if(val < root.val) {
        root.left = insertIntoBST(root.left, val);
    } else {
        root.right = insertIntoBST(root.right, val);
    }
    
    return root;
};
