// Runtime: 347 ms (Top 18.00%) | Memory: 83.8 MB (Top 70.00%)

var maxSumBST = function(root) {
    let max = 0;
    const dfs = (node) => {
        // NoNode
        if(!node) return [true, 0, Infinity, -Infinity];

        // LeafNode
        if(node && !node.left && !node.right) {
            max = Math.max(max, node.val);
            return [true, node.val, node.val, node.val]
        };

        const [isLeftValid, leftVal, leftMin, leftMax] = dfs(node.left);
        const [isRightValid, rightVal, rightMin, rightMax] = dfs(node.right);

        /**
        * To establish that the current node is also a valid BST, we need to verify the following:
        * 1. Left sub tree is a valid BST
        * 2. Right sub tree is a valid BST
        * 3. The values in the left BST are smaller than current node's value
        * 4. The values in the right BST are greater than current node's value
        **/
        if(isLeftValid && isRightValid && node.val > leftMax && node.val < rightMin) {
            max = Math.max(max, leftVal + rightVal + node.val);
            return [
                true,
                leftVal + rightVal + node.val,
                /**
                * 12
                * / \
                * 8 16
                * \ /
                * 9 15
                * \ /
                * 10 14
                * \ /
                * Infinity -Infinity
                * [Infinity and -Infinity are to depict NoNode cases]
                **/
                Math.min(node.val, leftMin),
                Math.max(node.val, rightMax)
            ];
        }

        return [false, 0, leftMax, rightMin];
    }
    dfs(root);

    return max;
};