const dfs = function(node, evenParent) {
    if (!node) return 0;
    
    const isEvenNode = node.val % 2 === 0;
    
    const left = dfs(node.left, isEvenNode);
    const right = dfs(node.right, isEvenNode);
    
    if (!evenParent) return left + right;
    return left + right + (node.left ? node.left.val : 0) + (node.right ? node.right.val : 0);
}

var sumEvenGrandparent = function(root) {
    if (!root) return 0;
    return dfs(root, false);
};
