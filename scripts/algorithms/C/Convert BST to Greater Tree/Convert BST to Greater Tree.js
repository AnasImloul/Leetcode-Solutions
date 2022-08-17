var convertBST = function(root) {
    let sum = 0;
    const go = (node) => {
        if (!node) return;
        go(node.right);
        sum += node.val;
        node.val = sum;
        go(node.left);
    }
    go(root);
    return root;
};
