// Runtime: 143 ms (Top 60.33%) | Memory: 51.8 MB (Top 40.50%)
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