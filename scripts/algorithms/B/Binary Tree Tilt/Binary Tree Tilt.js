// Runtime: 117 ms (Top 43.50%) | Memory: 47.8 MB (Top 17.51%)
var findTilt = function(root) {
    function helper(node, acc) {
        if (node === null) {
            return 0;
        }

        const left = helper(node.left, acc);
        const right = helper(node.right, acc);

        acc.sum += Math.abs(left - right);

        return left + node.val + right;
    }

    let acc = { sum: 0 };
    helper(root, acc);

    return acc.sum;
};