/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function(root) {
    return dfs(root)
};

const dfs = (root, path = '') => {
    if (!root.left && !root.right) return +(path + root.val)
    
    const left = root.left ? dfs(root.left, path + root.val) : 0
    const right = root.right ? dfs(root.right, path + root.val) : 0
    
    return left + right
}
