var increasingBST = function(root) {
    let newRoot = new TreeNode(-1);
    const newTree = newRoot;
    
    const dfs = (node) => {
        if (!node) return null;
        
        if (node.left) dfs(node.left);
        
        const newNode = new TreeNode(node.val);
        newRoot.right = newNode;
        newRoot.left = null;
        newRoot = newRoot.right;
        
        if (node.right) dfs(node.right);
    }
    dfs(root);
    
    return newTree.right;
};
