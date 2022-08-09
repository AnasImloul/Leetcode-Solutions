var addOneRow = function(root, val, depth) {
    if(depth == 1) {
        return new TreeNode(val, root);
    }
    
    const addRowHelper = (n = root, d = 1) => {
        if(!n) return;
        if(d + 1 == depth) {
            n.left = new TreeNode(val, n.left, null);
            n.right = new TreeNode(val, null, n.right);
            return;
        }
        addRowHelper(n.left, d + 1);
        addRowHelper(n.right, d + 1);
    } 
    addRowHelper();
    return root;
};
