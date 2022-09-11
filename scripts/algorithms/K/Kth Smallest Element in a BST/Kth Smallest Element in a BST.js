// Runtime: 75 ms (Top 95.24%) | Memory: 48.7 MB (Top 25.31%)
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 * this.val = (val===undefined ? 0 : val)
 * this.left = (left===undefined ? null : left)
 * this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    let stack = [];
    while(root != null || stack.length > 0) {
        while(root != null){
            stack.push(root);
            root = root.left
        }
        root = stack.pop();
        if(--k == 0) break;
        root = root.right;
    };

    return root.val;
};
