// Runtime: 160 ms (Top 41.18%) | Memory: 49.6 MB (Top 38.24%)
var sufficientSubset = function(root, limit) {
    const MIN = Number.MIN_SAFE_INTEGER;
    const sum = removeNodes(root, 0);

    if (sum < limit) return null;

    return root;

    function removeNodes(node, prevSum) {
        if (node == null) return MIN;
        if (node.left == node.right) return node.val + prevSum;

        const leftSum = removeNodes(node.left, prevSum + node.val);
        const rightSum = removeNodes(node.right, prevSum + node.val);

        if (leftSum < limit) node.left = null;
        if (rightSum < limit) node.right = null;

        if (node.left == node.right) return MIN;

        return node.left == null ? rightSum : leftSum;
    }
};