var isCousins = function(root, x, y) {
    let xHeight = 1;
    let xParent = null;
    let yHeight = 1;
    let yParent = null;
    
    const helper = (node, depth, parent) => {
        if(node === null)
            return null;
        
        helper(node.left, depth + 1, node);
        helper(node.right, depth + 1, node);
        
        let val = node.val;
        
        if(val === x) {
            xHeight = depth;
            xParent = parent;
        }
        
        if(val === y) {
            yHeight = depth;
            yParent = parent;
        }
    }
    
    helper(root, 0);
    
    return xHeight === yHeight && xParent !== yParent ? true : false;
};
