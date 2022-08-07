var sumOfLeftLeaves = function(root) {
    let total = 0;
    
    const go = (node, isLeft) => {
        if (isLeft && !node.left && !node.right) {
            total += node.val;
            return;
        }
        if (node.left) go(node.left, true);
        if (node.right) go(node.right, false)
    }
    
    go(root, false)
    
    return total;
};
