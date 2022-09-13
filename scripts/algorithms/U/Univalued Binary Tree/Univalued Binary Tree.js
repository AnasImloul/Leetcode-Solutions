// Runtime: 80 ms (Top 65.60%) | Memory: 42.1 MB (Top 90.67%)
var isUnivalTree = function(root) {
    if (!root) {
        return false;
    }

    const prev = root.val;
    const nodes = [root];

    for (const node of nodes) {
        if (node.val !== prev) {
            return false;
        }

        if (node.left) {
            nodes.push(node.left);
        }

        if (node.right) {
            nodes.push(node.right);
        }
    }

    return true;
};
    ```